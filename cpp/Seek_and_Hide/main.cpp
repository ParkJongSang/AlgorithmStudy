#include <iostream>

using namespace std;

int N, K;
int map[100001];
int queue[100001];
int front = 0;
int rear = 0;

bool is_inside(int n){
    if(n >= 0 && n < 100001){
        return true;
    }
    return false;
}

void bfs(int n){
    queue[rear] = n;
    rear += 1;
    map[n] = 0;
    int cur;
    while(front != rear){
        cur = queue[front];
        front += 1;

        if(is_inside(cur-1) && map[cur] + 1 < map[cur-1]){
            map[cur-1] = map[cur] + 1;
            queue[rear] = cur-1;
            rear += 1;
        }
        if(is_inside(cur+1) && map[cur] + 1 < map[cur+1]){
            map[cur+1] = map[cur] + 1;
            queue[rear] = cur+1;
            rear += 1;
        }
        if(is_inside(cur*2) && map[cur] + 1 < map[cur*2]){
            map[cur*2] = map[cur] + 1;
            queue[rear] = cur*2;
            rear += 1;
        }
    }

    return;
}

int main(void){
    cin >> N >> K;
    for(int i = 0; i < 100001; i++){
        map[i] = 987654321;
    }
    bfs(N);

    cout << map[K] << "\n";
    return 0;
}