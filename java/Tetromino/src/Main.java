import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    static int N, M;
    static int map[][];
    static Scanner sc = new Scanner(System.in);
    static int dx[] = {1,-1,0,0};
    static int dy[] = {0,0,-1,1};
    static int visit[][];
    static int max = 0;

    public static void main(String[] args) {
        //Initialize
        //int max = 0;
        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N][M];
        visit = new int[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] = sc.nextInt();
                visit[i][j] = 0;
            }
        }

        //toSolve Brute_force
        //System.out.println(solve_brute_force(map));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                visit[i][j] = 1;
                dfs(map, i, j, 0, 0);
                //이걸로 다 체크할수 있으나 t자는 판단할수 없음
                //고로 따로 만들어줘야 한다.
                visit[i][j] = 0;
                tShapeSum(map,i,j);
            }
        }

        System.out.println(max);

        //dfs

    }
    public static void tShapeSum(int map[][], int x, int y){
        LinkedList<Integer> list = new LinkedList<>();

        for(int i = 0; i < 4; i++){
            if(isInside(x+dx[i], y+dy[i])){
                list.add(map[x+dx[i]][y+dy[i]]);
            }
        }

        if(list.size() < 3){
            return;
        }

        Collections.sort(list);
        Collections.reverse(list);
        int count = 0;
        int sum = map[x][y];
        while(count != 3){
            sum += list.removeFirst();
            count++;
        }
        max = Math.max(max, sum);
    }
    public static void dfs(int[][] map, int x, int y, int sum, int depth){
        if(depth > 4){
            return;
        }else{
            max = Math.max(max, sum);
            for(int i = 0; i < 4; i++){
                if(isInside(x+dx[i], y+dy[i])){
                    if(visit[x+dx[i]][y+dy[i]] == 0){
                        visit[x+dx[i]][y+dy[i]] = 1;
                        dfs(map, x+dx[i], y+dy[i], sum+map[x][y], depth+1);
                        visit[x+dx[i]][y+dy[i]] = 0;
                    }
                }
            }
        }
    }

    public static int solve_brute_force(int[][] map){
        int max = -1;
        int sum = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(isInside(i,j) && isInside(i+1,j) && isInside(i,j+1) && isInside(i+1,j+1)){
                    //정사각형
                    sum = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j+1) && isInside(i,j+2) && isInside(i,j+3)){
                    //ㅡ모양
                    sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i+1,j) && isInside(i+2,j) && isInside(i+3,j)){
                    // | 모양
                    sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i+1,j) && isInside(i+1,j+1) && isInside(i+2,j+1)){
                    // S자
                    sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j+1) && isInside(i-1,j+1) && isInside(i-1,j+2)){
                    // 회전된 S자
                    sum = map[i][j] + map[i][j+1] + map[i-1][j+1] + map[i-1][j+2];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j+1) && isInside(i-1,j+1) && isInside(i,j+2)){
                    // ㅗ
                    sum = map[i][j] + map[i][j+1] + map[i-1][j+1] + map[i][j+2];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i+1,j) && isInside(i+1,j+1) && isInside(i+2,j)){
                    // ㅏ
                    sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j-1) && isInside(i+1,j-1) && isInside(i,j-2)){
                    // ㅜ
                    sum = map[i][j] + map[i][j-1] + map[i+1][j-1] + map[i][j-2];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i-1,j) && isInside(i-1,j-1) && isInside(i-2,j)){
                    // ㅓ
                    sum = map[i][j] + map[i-1][j] + map[i-1][j-1] + map[i-2][j];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i+1,j) && isInside(i+2,j) && isInside(i+2,j+1)){
                    // ㄴ
                    sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j+1) && isInside(i,j+2) && isInside(i-1,j+2)){
                    // ㄴ회전 1
                    sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i-1][j+2];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i-1,j) && isInside(i-2,j) && isInside(i-2,j-1)){
                    // ㄴ회전 2
                    sum = map[i][j] + map[i-1][j] + map[i-2][j] + map[i-2][j-1];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j-1) && isInside(i,j-2) && isInside(i+1,j-2)){
                    // ㄴ회전 3
                    sum = map[i][j] + map[i][j-1] + map[i][j-2] + map[i+1][j-2];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j+1) && isInside(i+1,j+1) && isInside(i+1,j+2)){
                    sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i+1,j) && isInside(i+1,j-1) && isInside(i+2,j-1)){
                    sum = map[i][j] + map[i+1][j] + map[i+1][j-1] + map[i+2][j-1];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i+1,j) && isInside(i+2,j) && isInside(i+2,j-1)){
                    sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j-1];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j-1) && isInside(i,j-2) && isInside(i-1,j-2)){
                    sum = map[i][j] + map[i][j-1] + map[i][j-2] + map[i-1][j-2];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i-1,j) && isInside(i-2,j) && isInside(i-2,j+1)){
                    sum = map[i][j] + map[i-1][j] + map[i-2][j] + map[i-2][j+1];
                    max = Math.max(max,sum);
                }
                if(isInside(i,j) && isInside(i,j+1) && isInside(i,j+2) && isInside(i+1,j+2)){
                    sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
                    max = Math.max(max,sum);
                }

            }

        }
        return max;
    }


    public static boolean isInside(int x, int y){
        return (x >= 0 && x < N) && (y >= 0 && y < M);
    }
}
