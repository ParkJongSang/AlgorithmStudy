#include <cstdio>

struct Point{
    int x;
    int y;
};

int N;
Point points[100000];

void debug(){
    for(int i = 0; i < N; i++){
        printf("%d %d\n", points[i].x, points[i].y);
    }
}

void sort(int left, int mid, int right){
    int l = left;
    int k = left;
    int r = mid+1;

    Point temp[100000];

    while(l <= mid && r <= right){
        if(points[l].x < points[r].x){
            temp[k].x = points[l].x;
            temp[k].y = points[l].y;
            k++; l++;
        }else if(points[l].x == points[r].x){
            if(points[l].y < points[r].y){
                temp[k].x = points[l].x;
                temp[k].y = points[l].y;
                k++; l++;
            }else{
                temp[k].x = points[r].x;
                temp[k].y = points[r].y;
                k++; r++;
            }
        }else{
            temp[k].x = points[r].x;
            temp[k].y = points[r].y;
            k++; r++;
        }
    }

    while(l <= mid){
        temp[k].x = points[l].x;
        temp[k].y = points[l].y;
        k++; l++;
    }
    while(r <= right){
        temp[k].x = points[r].x;
        temp[k].y = points[r].y;
        k++; r++;
    }
    
    for(int i = left; i <= right; i++){
        points[i].x = temp[i].x;
        points[i].y = temp[i].y;
    }
}

void partition(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        partition(left, mid);
        partition(mid+1, right);
        sort(left, mid, right);
    }else{
        return;
    }
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    partition(0, N-1);
    debug();

    return 0;
}