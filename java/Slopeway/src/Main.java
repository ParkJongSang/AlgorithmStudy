import java.util.Scanner;

public class Main {
    //첫째 줄에 N (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)이 주어진다. 둘째 줄부터 N개의 줄에 지도가 주어진다. 각 칸의 높이는 10보다 작거나 같은 자연수이다.

    //크기가 N×N인 지도가 있다. 지도의 각 칸에는 그 곳의 높이가 적혀져 있다.
    //
    //오늘은 이 지도에서 지나갈 수 있는 길이 몇 개 있는지 알아보려고 한다. 길이란 한 행 또는 한 열 전부를 나타내며, 한쪽 끝에서 다른쪽 끝까지 지나가는 것이다.
    //
    //길을 지나갈 수 있으려면 길에 속한 모든 칸의 높이가 모두 같아야 한다. 또는, 경사로를 놓아서 지나갈 수 있는 길을 만들 수 있다.
    //경사로는 높이가 항상 1이며, 길이는 L이다. 또, 개수는 매우 많아 부족할 일이 없다.
    //경사로는 낮은 칸과 높은 칸을 연결하며, 아래와 같은 조건을 만족해야한다.
    // - 경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
    // - 낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
    // - 경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.
    //아래와 같은 경우에는 경사로를 놓을 수 없다.
    // - 경사로를 놓은 곳에 또 경사로를 놓는 경우
    // - 낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
    // - 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
    // - 경사로를 놓다가 범위를 벗어나는 경우
    static int N;
    static int L;
    static int map[][];
    static boolean is_build[][];
    static int ans = 0;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        N = sc.nextInt();
        L = sc.nextInt();
        map = new int[N][N];
        is_build = new boolean[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                map[i][j] = sc.nextInt();
                is_build[i][j] = false;
            }
        }
        for(int i = 0; i < N; i++){
            buildXSlope(map, i);
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                is_build[i][j] = false;
            }
        }
        for(int i = 0; i < N; i++){
            buildYSlope(map, i);
        }

        System.out.println(ans);
    }

    public static void buildXSlope(int map[][], int x){
        int y = 0;
        int current_L = 1;
        while(isInside(x, y+1)){
            if(map[x][y] + 1 == map[x][y+1]){
                if(current_L >= L && isXBuild(x,y,L,0)){
                    XBuild(x,y,L,0);
                    current_L = 1;
                }else{
                    break;
                }
            }else if(map[x][y] - 1 == map[x][y+1]){
                if(isXBuild(x,y,L,1)){
                    XBuild(x,y,L,1);
                    current_L = 1;
                }else{
                    break;
                }
            }else if(map[x][y] == map[x][y+1]){
                if(current_L >= L){
                    current_L = L;
                }else{
                    current_L += 1;
                }
            }else{
                break;
            }

            y = y+1;
        }
        if(y == N - 1){
            ans = ans + 1;
        }
    }
    public static void XBuild(int x, int y, int len, int up_and_down){
        if(up_and_down == 0){//up
            for(int i = 0; i < len; i++){
                is_build[x][y-i] = true;
            }
        }else{//down
            for(int i = 0; i < len; i++){
                is_build[x][y+i+1] = true;
            }
        }
    }

    public static boolean isXBuild(int x, int y, int len, int up_and_down){
        int count = 0;

        if(up_and_down == 0){//up
            for(int i = 0; i < len; i++){
                if(isInside(x, y-i) && is_build[x][y-i] == false) count++;
            }
            return count == len;
        }else{//down
            int flat_length = 0;
            for(int i = 0; i < len; i++){
                if(isInside(x, y+i+1) && map[x][y+1] == map[x][y+1+i]) flat_length++;
                if(isInside(x, y+i+1) && is_build[x][y+i+1] == false) count++;
            }
            return flat_length == len && count == len;
        }
    }

    public static void buildYSlope(int map[][], int y){
        int x = 0;
        int current_L = 1;
        while(isInside(x+1, y)){
            if(map[x][y] + 1 == map[x+1][y]){
                if(current_L >= L && isYBuild(x,y,L,0)){
                    YBuild(x,y,L,0);
                    current_L = 1;
                }else{
                    break;
                }
            }else if(map[x][y] - 1 == map[x+1][y]){
                if(isYBuild(x,y,L,1)){
                    YBuild(x,y,L,1);
                    current_L = 1;
                }else{
                    break;
                }
            }else if(map[x][y] == map[x+1][y]){
                if(current_L >= L){
                    current_L = L;
                }else{
                    current_L += 1;
                }
            }else{
                break;
            }

            x = x+1;
        }
        if(x == N - 1){
            ans = ans + 1;
        }
    }

    public static void YBuild(int x, int y, int len, int up_and_down){
        if(up_and_down == 0){//up
            for(int i = 0; i < len; i++){
                is_build[x-i][y] = true;
            }
        }else{//down
            for(int i = 0; i < len; i++){
                is_build[x+i+1][y] = true;
            }
        }
    }

    public static boolean isYBuild(int x, int y, int len, int up_and_down){
        int count = 0;
        if(up_and_down == 0){//up
            for(int i = 0; i < len; i++){
                if(isInside(x-i, y) && is_build[x-i][y] == false) count++;
            }
            return count == len;
        }else{//down
            int flat_length = 0;
            for(int i = 0; i < len; i++){
                if(isInside(x+i+1, y) && map[x+1][y] == map[x+i+1][y]) flat_length++;
                if(isInside(x+i+1, y) && is_build[x+i+1][y] == false) count++;
            }
            return flat_length == len && count == len;
        }
    }

    public static boolean isInside(int x, int y){
        return (x >= 0 && x < N) && (y >= 0 && y < N);
    }
}
