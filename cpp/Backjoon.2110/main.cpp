#include <cstdio>
#define MAX_L 200000

typedef long long ll;

int C, N;
ll x_pos[MAX_L];
ll buf[MAX_L];

void merge(ll *ptr, int len){
    if(len < 2) return;
    int mid = len/2;
    merge(ptr, mid);
    merge(ptr+mid, len-mid);

    int i,j,k;
    i = 0; j = mid; k = 0;

    while(i < mid && j < len){
        if(ptr[i] < ptr[j]){
            buf[k++] = ptr[i++];
        }else {
            buf[k++] = ptr[j++];
        }
    }
    while(i < mid){
        buf[k++] = ptr[i++];
    }
    while(j < len){
        buf[k++] = ptr[j++];
    }
    for(int i = 0; i < len; i++){
        ptr[i] = buf[i];
    }
}

void debug(){
    for(int i = 0; i < N; i++){
        printf("%lld ", x_pos[i]);
    }
    printf("\n");
}

int main(void){
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++){
        scanf("%lld", &x_pos[i]);
    }
    merge(x_pos, N);

    ll start = 1;
    ll end = x_pos[N-1] - x_pos[0];
    ll ans = 0;

    while(start <= end){
        ll mid = (start + end) / 2;
        ll cnt = 1;
        ll benchmark= x_pos[0];
        for(int i = 1; i < N; i++){
            ll dist = x_pos[i] - benchmark;
            if(mid <= dist){
                cnt+=1;
                benchmark = x_pos[i];
            }
        }
        if(cnt >= C){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid -1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}