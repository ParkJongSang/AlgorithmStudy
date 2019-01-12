import java.util.Scanner;

public class Main {
    static int w, h;                                //배열의 높이와 너비
    static Pair R, B, O;                            //빨간공, 파란공, 출구
    static char[][] map;                            //맵 배열
    static String str;                              //입력용 문자열
    static Scanner sc = new Scanner(System.in);
    static int[] dx = {-1,1,0,0};                   //상하좌우
    static int[] dy = {0,0,-1,1};                   //상하좌우
    static int[][][][] visit;                       //앞 2차원 : 빨간공용 visit 뒤 2차원 : 파란공용 2차원
    static int ans;                                 //정답
    //static int red_depth;

    public static void main(String[] args){
        w = sc.nextInt();
        h = sc.nextInt();
        ans = 11;
        //red_depth = 0;
        map = new char[w][h];
        visit = new int[w][h][w][h];
        //b_visit = new int[w][h];
        Pair dir = new Pair(0,0);

        for(int i = 0; i < w; i++){
            str = sc.next();
            for(int j = 0; j < h; j++){
                map[i][j] = str.charAt(j);
                if(map[i][j] == 'B'){
                    B = new Pair(i,j);
                }else if(map[i][j] == 'R'){
                    R = new Pair(i,j);
                }else if(map[i][j] == 'O'){
                    O = new Pair(i,j);
                }
                visit[i][j][i][j] = 0;
            }
        }

        dfs(R,B,0);

        if(ans == 11) ans = -1;
        /*
        이 조건문에 걸리는 경우는 dfs의 depth가 10이 되는동안
        답을 찾지 못하였을 경우다.
        고로 -1을 출력하도록 ans를 바꾸어준다.
         */
        System.out.println(ans);

    }

    public static void dfs(Pair R, Pair B, int depth){
        boolean flagR = false;
        boolean flagB = false;

        if(depth > 10){
            return;
        }else{
            for(int i = 0; i < 4; i++) {
                Pair new_R = new Pair(R.x, R.y);
                Pair new_B = new Pair(B.x, B.y);
                //Pair cur_dir = new Pair(dx[i], dy[i]);

                if (firstStarterIsR(new_R, new_B, i)) {
                    //R이 먼저 움직여야한다. 움직잀수 있는 만큼
                    int rx = new_R.x, ry = new_R.y;
                    while (map[rx][ry] != '#') {
                        if (map[rx][ry] == 'O') {
                            flagR = true;
                        }
                        if(map[rx+dx[i]][ry+dy[i]] == '#'){
                            break;
                        }
                        rx += dx[i];
                        ry += dy[i];
                    }
                    int bx = new_B.x, by = new_B.y;
                    while (map[bx][by] != '#') {
                        if (map[bx][by] == 'O') {
                            flagB = true;
                        }
                        if(map[bx+dx[i]][by+dy[i]] == '#'){
                            break;
                        }
                        bx += dx[i];
                        by += dy[i];
                    }

                    if(rx == bx && ry == by){
                        if(i == 0) bx = rx + 1;
                        else if(i == 1) bx = rx - 1;
                        else if(i == 2) by = ry + 1;
                        else if(i == 3) by = ry - 1;
                    }
                    new_R.x = rx;
                    new_R.y = ry;
                    new_B.x = bx;
                    new_B.y = by;
                } else {
                    //B가 먼저 움직인다. 움직일 수 있는 만큼
                    int bx = new_B.x, by = new_B.y;
                    while (map[bx][by] != '#') {
                        if (map[bx][by] == 'O') {
                            flagB = true;
                        }
                        if(map[bx+dx[i]][by+dy[i]] == '#'){
                            break;
                        }
                        bx += dx[i];
                        by += dy[i];
                    }
                    int rx = new_R.x, ry = new_R.y;
                    while (map[rx][ry] != '#') {
                        if (map[rx][ry] == 'O') {
                            flagR = true;
                        }
                        if(map[rx+dx[i]][ry+dy[i]] == '#'){
                            break;
                        }
                        rx += dx[i];
                        ry += dy[i];
                    }
                    if(rx == bx && ry == by){
                        if(i == 0) rx = bx + 1;
                        else if(i == 1) rx = bx - 1;
                        else if(i == 2) ry = by + 1;
                        else if(i == 3) ry = by - 1;
                    }

                    new_R.x = rx;
                    new_R.y = ry;
                    new_B.x = bx;
                    new_B.y = by;

                }

                if(flagB && !flagR) {
                    /*
                    파란공만 통과하고 빨간공은 통과하지 못한 경우이다
                    찾고자 하는 경우가 아니므로 다시 false로 초기화해준다.
                    초기화 해주지 않을경우 true인 상태로 반복문을 순회하게 된다.
                     */
                    flagB = false;
                }else if(flagB && flagR){
                    /*
                    파란공과 빨간공이 동시에 통과한 경우이다.
                    이 경우도 찾고자 하는 경우가 아니므로 두 flag모두 false로 초기화해준다.
                    초기화 하지 않을경우 둘다 true인 상태로 반복문을 순회하게 된다.
                     */
                    flagB = false;
                    flagR = false;
                }else if(!flagB && flagR){
                    if(ans >= depth+1){
                        /*
                        원하는 답을 찾았을 경우다
                        파란공은 통과하지 못하였으나 빨간공은 통과한 경우
                        이전에 찾은 답이 지금 찾은 답보다 크다면
                        지금 찾은 답으로 ans값을 변경해준다.
                         */
                        ans = depth + 1;
                    }
                }else if(visit[new_R.x][new_R.y][new_B.x][new_B.y] == 0) {
                    visit[new_R.x][new_R.y][new_B.x][new_B.y] = 1;
                    //swap(map, R.x, R.y, new_R.x, new_R.y);
                    //swap(map, B.x, B.y, new_B.x, new_B.y);
                    /*
                    굳이 스왑을 안해줘도 된다. 디버깅 하는 과정에서 map이 변하는 과정을 보고싶었기에
                    추가한 swap이다. 없어도 동작할듯.
                     */
                    dfs(new_R, new_B, depth + 1);
                    //swap(map, B.x, B.y, new_B.x, new_B.y);
                    //swap(map, R.x, R.y, new_R.x, new_R.y);
                    visit[new_R.x][new_R.y][new_B.x][new_B.y] = 0;
                }

            }

        }
    }

    public static void swap(char[][] map, int x1, int y1, int x2, int y2){
        char temp = map[x1][y1];
        map[x1][y1] = map[x2][y2];
        map[x2][y2] = temp;
    }

    public static boolean firstStarterIsR(Pair R, Pair B, int dir){
        boolean first_starter_is_R = false;
        switch (dir){
            case 0:
                //상
                if(R.x < B.x){
                    first_starter_is_R = true;
                }
                break;
            case 1:
                //하
                if(R.x >= B.x){
                    first_starter_is_R = true;
                }
                break;
            case 2:
                //좌
                if(R.y < B.y){
                    first_starter_is_R = true;
                }
                break;
            case 3:
                //우
                if(R.y >= B.y){
                    first_starter_is_R = true;
                }
                break;
        }
        return first_starter_is_R;
    }
}


class Pair{
    int x;
    int y;

    Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}

