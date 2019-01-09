import java.util.Scanner;

public class Main {
    static int N;
    static int L;
    static int dx[] = {1,0,-1,0};
    static int dy[] = {0,-1,0,1};
    static int R;
    static int count;
    static int sum;
    static int isMove;
    static int[][] A;
    static int[][] visit;
    static int ans;
    static int[][] isChange;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        N = sc.nextInt();
        L = sc.nextInt();
        R = sc.nextInt();

        A = new int[N][N];
        visit = new int[N][N];
        isChange = new int[N][N];

        for(int r = 0; r < N; r++){
            for(int c = 0; c < N; c++){
                A[r][c] = sc.nextInt();
                visit[r][c] = 0;
                isChange[r][c] = 0;
            }
        }

        while(true){
            isMove = 0;
            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    if(visit[r][c] == 0){
                        count = 0;
                        sum = 0;
                        isMove++;
                        dfs(r,c);
                    }
                    if(isChange[r][c] == 0){
                        changeValue(r,c);
                    }
                }
            }

            if(isMove == N*N){
                break;
            }else{
                ans++;
            }

            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    visit[r][c] = 0;
                    isChange[r][c] = 0;
                }
            }
        }

        System.out.println(ans);
    }

    //열린 경계를 탐색하기 위한 dfs
    public static void dfs(int r, int c){
        if(visit[r][c] == 1){
            return;
        }else{
            count++;
            sum += A[r][c];
            visit[r][c] = 1;
            for(int i = 0; i < 4; i++) {

                int next_x = r + dx[i];
                int next_y = c + dy[i];


                if (isInside(next_x, next_y)) {
                    int gap = Math.abs(A[next_x][next_y] - A[r][c]);
                    if (gap >= L && gap <= R && visit[next_x][next_y] == 0) {
                        dfs(next_x, next_y);
                    }
                }
            }
        }
    }

    //열린 경계들의 값을 바꿔주는 dfs
    public static void changeValue(int r, int c){
        if(isChange[r][c] == 1){
            return;
        }else{
            isChange[r][c] = 1;
            A[r][c] = sum / count;
            for(int i = 0; i < 4; i++) {

                int next_x = r + dx[i];
                int next_y = c + dy[i];

                if (isInside(next_x, next_y) && visit[next_x][next_y] == 1) {
                    changeValue(next_x,next_y);
                }
            }
        }
    }

    public static boolean isInside(int a, int b){
        return (a>=0 && a<N) && (b>=0 && b<N);
    }
}
