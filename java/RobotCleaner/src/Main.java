import javafx.scene.transform.Scale;

import java.util.Scanner;

public class Main {
    //첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)
    //둘째 줄에 로봇 청소기가 있는 칸의 좌표 (r, c)와 바라보는 방향 d가 주어진다. d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.
    //셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 빈 칸은 0, 벽은 1로 주어진다. 장소의 모든 외곽은 벽이다.

    //로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.


    static int N,M;
    static int map[][];
    static boolean isCleaned[][];
    static int cleaner_x, cleaner_y, cleaner_dir;
    static Scanner sc = new Scanner(System.in);
    static int dir[][] = {{-1,0},{0,1},{1,0},{0,-1}};

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N][M];
        isCleaned = new boolean[N][M];

        cleaner_x = sc.nextInt();
        cleaner_y = sc.nextInt();
        cleaner_dir = sc.nextInt();

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] = sc.nextInt();
                if(map[i][j] == 1){
                    isCleaned[i][j] = true;
                }else{
                    isCleaned[i][j] = false;
                }
            }
        }

        System.out.println(cleanRoom(map, isCleaned, cleaner_x, cleaner_y, cleaner_dir));

    }

    public static int cleanRoom(int map[][], boolean isCleaned[][], int cleaner_x, int cleaner_y, int cleaner_dir){
        //현재 위치를 청소한다.
        //현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
        //왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        //왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
        //네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        //네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
        int ans = 0;
        int cur_dir = cleaner_dir;
        int cur_x = cleaner_x;
        int cur_y = cleaner_y;
        while(true){
            //현재위치를 청소한다.
            if(isCleaned[cur_x][cur_y] == false){
                ans = ans + 1;
                isCleaned[cur_x][cur_y] = true;
            }
            //왼쪽 탐색
            int left_dir = checkLeft(cur_dir);
            if(isCleaned[cur_x + dir[left_dir][0]][cur_y + dir[left_dir][1]] == false){
                cur_dir = left_dir;
                cur_x = cur_x + dir[cur_dir][0];
                cur_y = cur_y + dir[cur_dir][1];
            }else{
                if(stopCleaner(map, isCleaned, cur_x, cur_y, cur_dir)){
                    //4방향 모두 청소했거나 벽인경우 뒤쪽이 벽이라면 멈춘다.
                    break;
                }else{
                    if(checkAllSide(isCleaned, cur_x, cur_y)){
                        int backside = checkLeft(checkLeft(cur_dir));
                        //방향은 바꾸지 말고 후진만 한다.
                        cur_x = cur_x + dir[backside][0];
                        cur_y = cur_y + dir[backside][1];
                    }else{
                        //왼쪽 방향에 청소할 공간이 없다면
                        //회전만 한다.
                        cur_dir = left_dir;
                    }
                }
            }
        }
        return ans;
    }

    public static boolean stopCleaner(int map[][], boolean isCleaned[][], int cleaner_x, int cleaner_y, int cleaner_dir){

        if(checkAllSide(isCleaned, cleaner_x, cleaner_y)){
            //4방향이 청소되어있거나 혹은 벽이다.
            int backside = checkLeft(checkLeft(cleaner_dir));
            if(map[cleaner_x + dir[backside][0]][cleaner_y + dir[backside][1]] == 1){
                //뒤쪽이 벽이다.
                return true;
            }else{
                //뒤쪽이 벽이 아니다.
                return false;
            }
        }
        //4방향중 적어도 하나는 청소되어있지 않다.
        return false;
    }

    public static boolean checkAllSide(boolean isCleaned[][], int cleaner_x, int cleaner_y){
        return isCleaned[cleaner_x+1][cleaner_y] == true &&isCleaned[cleaner_x-1][cleaner_y] == true
                &&isCleaned[cleaner_x][cleaner_y+1] == true &&isCleaned[cleaner_x][cleaner_y-1] == true;
    }

    public static int checkLeft(int dir){
        int return_dir = 0;
        switch (dir){
            case 0://북
                return_dir = 3;
                break;
            case 1://동
                return_dir = 0;
                break;
            case 2://남
                return_dir = 1;
                break;
            case 3://서
                return_dir = 2;
                break;

        }
        return return_dir;
    }
}


