#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

int A[4000], B[4000], C[4000], D[4000];
int set_A[16000000];
int set_B[16000000];
ll ans = 0;
int N;

ll cnt_equal(int *arr, int idx){
    int cmp = arr[idx];
    ll ret = 0;
    int left = -1, right = 1;
    int cur = idx;
    while(arr[cur + left] == cmp && cur + left >= 0){
        ret += 1;
        cur += left;
    }
    cur = idx;
    while(arr[cur + right] == cmp && cur + right < N*N){
        ret += 1;
        cur += right;
    }
    return ret;
}

int bin_search(int *arr, int idx, int key){
    int left = 0;
    int right = idx-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] > key){
            right = mid - 1;
        }else if(arr[mid] < key){
            left = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

void solve(int *arr_A, int *arr_B, int idx){
    int i = 0;
    while(i < idx){
        int tmp = bin_search(arr_B, idx, -1 * arr_A[i]);
        ll arr_a_equal_cnt = cnt_equal(arr_A, i) + 1;
        //printf("%lld\n", arr_a_equal_cnt);
        if(tmp != -1){
            ll arr_b_equal_cnt = cnt_equal(arr_B, tmp) + 1;
            ans += arr_a_equal_cnt * arr_b_equal_cnt;
            //printf("%lld\n", arr_b_equal_cnt);
        }
        i = i + arr_a_equal_cnt;
    }
}

void debug(int *arr, int length){
    for(int i =0 ; i < length; i++){
        printf("%d ", arr[i]);
    }printf("\n");
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    int idx = 0;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            set_A[idx] = A[i] + B[j];
            set_B[idx++] = C[i] + D[j];
        }
    }
    sort(set_A, set_A + (N*N));
    sort(set_B, set_B + (N*N));
    //debug(set_A, N*N);
    //debug(set_B, N*N);
    solve(set_A, set_B, idx);
    printf("%lld\n", ans);
    return 0;
}