import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int N, M;
    static Scanner sc = new Scanner(System.in);
    static int map[][];
    static int dir[][] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};//1: 동쪽, 2: 서쪽, 3: 북쪽, 4:남쪽


    public static void main(String[] args) {
        //Initialize
        Dice dice = new Dice(0,0,0,0,0,0);
        Queue<Integer> orders = new LinkedList<>();

        int dice_pos_x;
        int dice_pos_y;
        int number_of_orders;

        N = sc.nextInt(); M = sc.nextInt();
        dice_pos_x = sc.nextInt();
        dice_pos_y = sc.nextInt();
        number_of_orders = sc.nextInt();

        map = new int[N][M];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < number_of_orders; i++){
            orders.add(sc.nextInt());
        }

        //toSolve
        solve(dice, orders, dice_pos_x, dice_pos_y);

    }

    public static void solve(Dice dice, Queue<Integer> orders, int dice_pos_x, int dice_pos_y){
        int cur_dice_pos_x = dice_pos_x;
        int cur_dice_pos_y = dice_pos_y;
        while (!orders.isEmpty()){
            int cur_order = orders.poll();
            if(isInside(cur_dice_pos_x + dir[cur_order][0], cur_dice_pos_y + dir[cur_order][1])){
                diceRoll(dice, cur_order);
                cur_dice_pos_x += dir[cur_order][0];
                cur_dice_pos_y += dir[cur_order][1];
                if(map[cur_dice_pos_x][cur_dice_pos_y] == 0){
                    map[cur_dice_pos_x][cur_dice_pos_y] = returnDiceDown(dice);
                }else{
                    dice.down = map[cur_dice_pos_x][cur_dice_pos_y];
                    map[cur_dice_pos_x][cur_dice_pos_y] = 0;
                }
                System.out.println(dice.up);
            }else{
                continue;
            }
        }
    }

    public static void diceRoll(Dice dice, int dir){
        int temp;
        if(dir == 1){//동
            temp = dice.up;
            dice.up = dice.left;
            dice.left = dice.down;
            dice.down = dice.right;
            dice.right = temp;
        }else if(dir == 2){//서
            temp = dice.up;
            dice.up = dice.right;
            dice.right = dice.down;
            dice.down = dice.left;
            dice.left = temp;
        }else if(dir == 3){//북
            temp = dice.up;
            dice.up = dice.front;
            dice.front = dice.down;
            dice.down = dice.back;
            dice.back = temp;
        }else if(dir == 4){//남
            temp = dice.up;
            dice.up = dice.back;
            dice.back = dice.down;
            dice.down = dice.front;
            dice.front = temp;
        }
    }

    public static int returnDiceDown(Dice dice){
        return dice.down;
    }

    public static boolean isInside(int x, int y){
        return (x >= 0 && x < N) && (y >= 0 && y < M);
    }
}

class Dice{
    int up;
    int down;
    int left;
    int right;
    int front;
    int back;

    Dice(int up, int down, int left, int right, int front, int back){
        this.up = up;
        this.down = down;
        this.left = left;
        this.right = right;
        this.front = front;
        this.back = back;
    }
}
