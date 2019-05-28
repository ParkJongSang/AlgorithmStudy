#include <iostream>

using namespace std;
 
int M, N;
long L;
long hunter[100000];
long animal[100000][2];
int ans = 0;

void merge_sort_hunter(int left, int mid, int right){
    int i, j ,k;
     
    i = left;
    j = mid + 1;
    k = left;
 
    long tmp_arr[100000];
 
    while (i <= mid && j <= right) {
        if (hunter[i] <= hunter[j]) {
            tmp_arr[k] = hunter[i];
            i++;
        } else {
            tmp_arr[k] = hunter[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        for (int m = j; m <= right; m++) {
            tmp_arr[k] = hunter[m];
            k++;
        }
    } else {
        for (int m = i; m <= mid; m++) {
            tmp_arr[k] = hunter[m];
            k++;
        }
    }
 
    for (int m = left; m <= right; m++) {
        hunter[m] = tmp_arr[m];
    }
}
 
void merge_sort_animal(int left, int mid, int right){
    int i, j ,k;
     
    i = left;
    j = mid + 1;
    k = left;
 
    long tmp_arr[100000][2];
 
    while (i <= mid && j <= right) {
        if (animal[i][0] <= animal[j][0]) {
            if(animal[i][0] == animal[j][0]){
                if(animal[i][1] <= animal[j][1]){
                    tmp_arr[k][0] = animal[i][0];
                    tmp_arr[k][1] = animal[i][1];
                    i++;
                }else{
                    tmp_arr[k][0] = animal[j][0];
                    tmp_arr[k][1] = animal[j][1];
                    j++;
                }
            }else{
                tmp_arr[k][0] = animal[i][0];
                tmp_arr[k][1] = animal[i][1];
                i++;
            }
        } else {
            tmp_arr[k][0] = animal[j][0];
            tmp_arr[k][1] = animal[j][1];
            j++;
        }
        k++;
    }
    if(i > mid){
        for (int m = j; m <= right; m++) {
            tmp_arr[k][0] = animal[m][0];
            tmp_arr[k][1] = animal[m][1];
            k++;
        }
    } else {
        for (int m = i; m <= mid; m++) {
            tmp_arr[k][0] = animal[m][0];
            tmp_arr[k][1] = animal[m][1];
            k++;
        }
    }
 
    for (int m = left; m <= right; m++) {
        animal[m][0] = tmp_arr[m][0];
        animal[m][1] = tmp_arr[m][1];
    }
}
 
//사냥꾼 머지소트
void partition_hunter(int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        partition_hunter(left, mid);
        partition_hunter(mid+1, right);
        merge_sort_hunter(left, mid, right);
    }
}
 
//동물 x기준 머지소트
void partition_animal(int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        partition_animal(left, mid);
        partition_animal(mid+1, right);
        merge_sort_animal(left, mid, right);
    }
}

int dist(int a, int b, int c){
    return abs(a-b)+c;
}

int solve(){
    int c = 0;
    int hunter_idx = 0;

    for(int i = 0; i < N; i++){
        while(hunter_idx != M-1 && hunter[hunter_idx+1] < animal[i][0]){
            //다음 사냥꾼의 위치가 현재 동물의 x좌표보다 클떄까지 사냥꾼을 증가
            hunter_idx += 1;
        }
        if(dist(hunter[hunter_idx], animal[i][0], animal[i][1]) <= L){
            //현재 사냥꾼과 동물을 비교해서 만족하면 ++
            c++;
        }else{
            //그렇지 않을경우 다음 사냥꾼과 비교해서 ++
            if(dist(hunter[hunter_idx+1], animal[i][0], animal[i][1]) <= L){
                c++;
            }
        }
    }

    return c;
}
 
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
 
    cin >> M >> N >> L;
 
    for(int i = 0; i < M ; i++){
        cin >> hunter[i];
    }
 
    for(int i = 0; i < N ; i++){
        cin >> animal[i][0] >> animal[i][1];
    }

    partition_hunter(0, M-1);
    partition_animal(0, N-1);
 
    cout << solve() << "\n";
    return 0;
}