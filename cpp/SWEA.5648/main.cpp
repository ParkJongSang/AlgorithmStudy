#include <stdio.h>

int N;
int map[4005][4005];
int atom[1000][4];
bool collided[4005][4005];

void remove_atom(int n, int *pn_size){
    int last_idx = (*pn_size) - 1;
    atom[n][0] = atom[last_idx][0];
    atom[n][1] = atom[last_idx][1];
    atom[n][2] = atom[last_idx][2];
    atom[n][3] = atom[last_idx][3];
    (*pn_size)--;
}

int solve(){
    int size = N;
    int ans = 0;

    for(int i = 0 ; i < N; i++){
        atom[i][0] = atom[i][0] * 2;
        atom[i][1] = atom[i][1] * 2;
        visit[atom[i][0]][atom[i][1]] += 1;
    }

    for(int i = 0; i < 4000; i++){
        for(int j = 0; j < size; j++){
            int &x = atom[j][0];
            int &y = atom[j][1];
            int d = atom[j][2];
            visit[x][y] -= 1;
            if(d == 0) y++;
            else if(d == 1) y--;
            else if(d == 2) x--;
            else if(d == 3) x++;

            if(atom[j][0] < 0 || atom [j][0] > 4000 || atom[j][1] < 0 || atom[j][1] > 4000){
                remove_atom(j, &size);
                j--;
            }else{
                visit[x][y]++;
                if(visit[x][y] >= 2) collided[x][y] = true;
            }
        }

        for(int j = 0; j < size; j++){
            int x = atom[j][0];
            int y = atom[j][1];
            if(collided[x][y] == true){
                visit[x][y]--;
                ans += atom[j][3];
                remove_atom(j, &size);
                j--;
            }
        }
        if(size == 0) break;
    }
    return ans;
}
int main(void){
    int test_case = 0;
    scanf("%d", &test_case);

    for(int tc = 1; i <= test_case; tc++){

        scanf("%d", &N);

        for(int i = 0; i < N; i++){
            scanf("%d %d %d %d", &atom[i][0], &atom[i][1], &atom[i][2], &atom[i][3]);
            atom[i][0] += 1000;
            atom[i][1] += 1000;
        }
        
        int ans = solve();

        printf("#%d %d\n", test_case, ans);

    }
    return 0;
}