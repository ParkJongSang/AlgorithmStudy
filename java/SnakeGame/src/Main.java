import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int N, K;
    static int move_count;
    static Map map[][];
    static int dir[][] = {{0,1},{1,0},{0,-1},{-1,0}};// -1: 좌회전  +1: 우회전
    static Queue<Move> move_list = new LinkedList<>();
    static Snake snake;
    static int ans = 0;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        N = sc.nextInt();
        map = new Map[N+1][N+1];
        K = sc.nextInt();

        Point head = new Point(1,1,0);
        Point tail = new Point(1,1,0);
        snake = new Snake(head, tail, 0);

        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){
                map[i][j] = new Map();
            }
        }

        zeroize(map);

        for(int i = 0; i < K; i++){
            int apple_x = sc.nextInt();
            int apple_y = sc.nextInt();
            map[apple_x][apple_y].value = 2;
        }

        move_count = sc.nextInt();

        for(int i = 0; i < move_count; i++){
            int time = sc.nextInt();
            char dir_order = sc.next().charAt(0);
            Move temp = new Move(time, dir_order);
            move_list.add(temp);
        }

        map[head.x][head.y].value = 1;

        moveSnake(snake);

        System.out.println(ans);
    }

    public static void zeroize(Map arr[][]){
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){
                arr[i][j].value = 0;
                arr[i][j].order = -1;
                //내가 0을 특별한 무엇인가로 사용하였는지 확인할것
                //무언가로 사용했다면 초기화를 0으로 하는 것을 다시한번 고려해볼것
            }
        }
    }

    public static boolean isInside(int x, int y){
        return (x >= 1 && x < N+1) && (y >= 1 && y < N+1);
    }

    public static void moveSnake(Snake snake){
        int head_dir = 0;
        int tail_dir = 0;
        int tail_delay = 0;
        while(true){

            snake.head.x = snake.head.x+dir[head_dir][0];
            snake.head.y = snake.head.y+dir[head_dir][1];

            if(isInside(snake.head.x, snake.head.y) && map[snake.head.x][snake.head.y].value != 1){
                ans++;
                //System.out.println(ans++);
                //for(int i = 1; i < N+1; i++){
                //    for(int j = 1; j < N+1; j++){
                //        System.out.print(map[i][j].value);
                //    }
                //    System.out.println();
                //}
                //System.out.println();
                if(map[snake.head.x][snake.head.y].value == 2){
                    map[snake.head.x][snake.head.y].value = 1;
                    snake.bodyLenth = snake.bodyLenth + 1;
                    tail_delay = tail_delay+1;
                }else{
                    map[snake.head.x][snake.head.y].value = 1;
                    if(map[snake.tail.x][snake.tail.y].order != -1){
                        tail_dir = map[snake.tail.x][snake.tail.y].order;
                        map[snake.tail.x][snake.tail.y].order = -1;
                    }
                    map[snake.tail.x][snake.tail.y].value = 0;
                    snake.tail.x = snake.tail.x+dir[tail_dir][0];
                    snake.tail.y = snake.tail.y+dir[tail_dir][1];
                }
            }else{
                ans++;
                //System.out.println(ans++);
                //for(int i = 1; i < N+1; i++){
                //    for(int j = 1; j < N+1; j++){
                //        System.out.print(map[i][j].value);
                //    }
                //    System.out.println();
                //}
                return;
            }

            if(!move_list.isEmpty()){
                if(ans == move_list.peek().time){
                    Move cur_move = move_list.poll();
                    map[snake.head.x][snake.head.y].order = changeDir(cur_move.dir_order, head_dir);
                    head_dir = changeDir(cur_move.dir_order, head_dir);
                }
            }

        }
    }

    public static int changeDir(char order, int cur_dir){
        if(order == 'D'){
            if(cur_dir+1 >= 4){
                return 0;
            }else{
                return cur_dir+1;
            }
        }else if(order == 'L'){
            if(cur_dir-1 < 0){
                return 3;
            }else{
                return cur_dir-1;
            }
        }
        return -1;
    }

}

class Move{
    int time;
    char dir_order;

    Move(int time, char dir_order){
        this.time = time;
        this.dir_order = dir_order;
    }
}

class Point{
    int x;
    int y;
    int dir;

    Point(int x, int y, int dir){
        this.x = x;
        this.y = y;
        this.dir = dir;
    }
}

class Map{
    int value;
    int order;
}

class Snake{
    Point head;
    Point tail;
    int bodyLenth;

    Snake(Point head, Point tail, int bodyLenth){
        this.head = head;
        this.tail = tail;
        this.bodyLenth = bodyLenth;
    }
}
