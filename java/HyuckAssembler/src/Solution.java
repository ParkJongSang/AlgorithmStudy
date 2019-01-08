import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
DFS로 푸는 혁셈블리어 문제

다른 문자는 문자그대로 풀이하면 되지만 ?의 경우 4갈래로 갈 수 있는 확률이 동일하다고 되어있다.

따라서 4방향 모두 갔을때의 경우를 생각해 봐야한다.

DFS를 잘 구현할 수 있는지 묻는 문제

 */

public class Solution {

    static int T;
    static int R,C;
    static char[][] map;
    static boolean[][][][] visited;
    static boolean find;
    static int[] directionForX = {-1,0,1,0};
    static int[] directionForY = {0,1,0,-1};

    //0 up, 1 right, 2 down, 3 left

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());
        int t = 1;

        while(T-- > 0) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            map = new char[R][C];
            visited = new boolean[R][C][4][16];
            find = false;
            boolean hasEnd = false;

            for (int i = 0; i < R; i++) {
                map[i] = br.readLine().toCharArray();
                for (int j = 0; j < C; j++) {
                    if(map[i][j] == '@')
                        hasEnd = true;
                }
            }

            if(hasEnd) {
                solve(0,0,1,0);
            }

            System.out.printf("#%d %s\n",t++,find ? "YES" : "NO");
        }
    }

    static void solve(int x, int y, int d, int memory) {
        if(find) return ;

        if(map[x][y] == '@') {
            find = true;
            return ;
        }

        if(visited[x][y][d][memory]) return ;

        visited[x][y][d][memory] = true;

        int nextDirection = d;
        int nextMemory = memory;

        switch(map[x][y]) {
            case '<': nextDirection = 3; break;
            case '>': nextDirection = 1; break;
            case '^': nextDirection = 0; break;
            case 'v': nextDirection = 2; break;
            case '_': nextDirection = (memory == 0 ? 1 : 3); break;
            case '|': nextDirection = (memory == 0 ? 2 : 0); break;
            case '+': nextMemory = (memory == 15 ? 0 : memory+1); break;
            case '-': nextMemory = (memory == 0 ? 15 : memory-1); break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                nextMemory = map[x][y] -'0';
                break;
        }

        if (map[x][y] == '?') {
            for (int i = 0; i < 4; i++) {
                if(x+ directionForX[i] < 0 ) {
                    solve(R -1,y+ directionForY[i],i,nextMemory);
                }
                else if(x+ directionForX[i] >= R) {
                    solve(0,y+ directionForY[i],i,nextMemory);
                }
                else if ( y+ directionForY[i] < 0) {
                    solve(x+ directionForX[i],C-1,i,nextMemory);
                }
                else if ( y+ directionForY[i] >= C) {
                    solve(x+ directionForX[i],0,i,nextMemory);
                }
                else {
                    solve(x+ directionForX[i],y+ directionForY[i],i,nextMemory);
                }
            }
        }
        else {
            if(x+ directionForX[nextDirection] < 0 ) {
                solve(R -1,y+ directionForY[nextDirection],nextDirection,nextMemory);
            }
            else if(x+ directionForX[nextDirection] >= R) {
                solve(0,y+ directionForY[nextDirection],nextDirection,nextMemory);
            }
            else if ( y+ directionForY[nextDirection] < 0) {
                solve(x+ directionForX[nextDirection],C-1,nextDirection,nextMemory);
            }
            else if ( y+ directionForY[nextDirection] >= C) {
                solve(x+ directionForX[nextDirection],0,nextDirection,nextMemory);
            }
            else {
                solve(x+ directionForX[nextDirection],y+ directionForY[nextDirection],nextDirection,nextMemory);
            }
        }
    }
}