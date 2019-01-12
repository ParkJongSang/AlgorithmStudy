import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int N;
    static int map[][];
    static int isFull[][];
    static int ans;
    static int isMerged[][];
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,-1,1};

    public static void main(String[] args) {
        N = sc.nextInt();
        ans = -1;

        isFull = new int[N][N];
        map = new int[N][N];
        isMerged = new int[N][N];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                map[i][j] = sc.nextInt();
                if(map[i][j] != 0){
                    isFull[i][j] = 1;
                }else{
                    isFull[i][j] = 0;
                }
                isMerged[i][j] = 0;
            }
        }


        dfs(map, 0);

        System.out.print(ans);
    }

    public static boolean isInside(int a, int b){
        return (a>=0 && a<N) && (b>=0 && b<N);
    }

    public static void dfs(int[][] map, int depth){
        if(depth >= 5){
            //check(map);
            return;
        }else{
            for(int i = 0; i < 4; i++){
                int[][] primal = new int[N][N];
                clone(primal,map);
                //이전상태 저장
                moveAllBlock(map, i);
                //System.out.println();
                dfs(map,depth+1);
                clone(map, primal);
                //이전상태 복구

            }
        }
    }

    public static void moveAllBlock(int[][] map, int dir){
        if(dir == 0) {
            //상
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(map[i][j] != 0){
                        moveOneBlock(map, i, j ,dir);
                    }

                }
            }
        }else if(dir == 1){
            //하
            for(int i = N-1; i >= 0; i--){
                for(int j = 0; j < N; j++){
                    if(map[i][j] != 0){
                        moveOneBlock(map, i, j ,dir);
                    }
                }
            }
        }else if(dir == 2){
            //좌
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(map[i][j] != 0){
                        moveOneBlock(map, i, j ,dir);
                    }
                }
            }
        }else if(dir == 3){
            //우
            for(int i = 0; i < N; i++){
                for(int j = N-1; j >= 0; j--){
                    if(map[i][j] != 0){
                        moveOneBlock(map, i, j ,dir);
                    }
                }
            }
        }
        zeroize(isMerged);
    }

    public static void moveOneBlock(int[][] map, int x, int y, int dir){
        int tx = x;
        int ty = y;
        while(isInside(tx+dx[dir], ty+dy[dir]) && map[tx+dx[dir]][ty+dy[dir]] == 0){
            tx = tx+dx[dir];
            ty = ty+dy[dir];
        }

        int value =  map[x][y];
        map[x][y] = 0;

        if(isInside(tx+dx[dir], ty+dy[dir]) && value == map[tx+dx[dir]][ty+dy[dir]] && isMerged[tx+dx[dir]][ty+dy[dir]] == 0){
            //이동하려는 방향쪽으로 한칸만 더 갔을때 같은 값이면 합쳐질 수 있다.
            //이미 Merge가 진행된 블록이라면 더이상 Merge를 진행하지 않는다.
            //문제에도 나와있는 조건
            //문제를 자세히 볼것

            //Merge를 검사하는 조건이 없었다면 다음과같은 테스트케이스가 통과됨
            /*
            2  2  2  2  2                   32  32  32  32  32
            2  2  2  2  2                   0   0   0   0   0
            4  4  4  4  4    Up 1단계 진행->  0   0   0   0   0
            8  8  8  8  8                   0   0   0   0   0
            16 16 16 16 16                  0   0   0   0   0
            위 방식은 정상적인 진행이 아니고 정상적인 진행은
            2  2  2  2  2                   4   4   4   4   4
            2  2  2  2  2                   4   4   4   4   4
            4  4  4  4  4    Up 1단계 진행->  8   8   8   8   8
            8  8  8  8  8                   16  16  16  16  16
            16 16 16 16 16                  0   0   0   0   0
            다음과 같이 진행되어야 한다.
             */
            isMerged[tx+dx[dir]][ty+dy[dir]] = 1;
            int merge_value = map[tx+dx[dir]][ty+dy[dir]] + value;
            if(ans < merge_value) ans = merge_value;
            map[tx+dx[dir]][ty+dy[dir]] = merge_value;
        }else{
            if(ans < value) ans = value;
            map[tx][ty] = value;
        }
    }

    public static void clone(int[][] a, int[][] b){
        for(int i = 0; i < a.length; i++){
            for(int j = 0; j < a.length; j++){
                a[i][j] = b[i][j];
            }
        }
    }

    public static void zeroize(int[][] arr){
        for(int i = 0; i < arr.length; i++){
            for(int j = 0; j < arr.length; j++){
                arr[i][j] = 0;
            }
        }
    }

}