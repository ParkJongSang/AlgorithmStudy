import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static int N, M;
    public static Scanner sc = new Scanner(System.in);
    public static int line[] = new int[32000];
    public static Queue<Order> q = new LinkedList<>();
    public static int count = 0;
    public static boolean is_choice[] = new boolean[32001];

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();

        for(int i = 0; i < M; i++){
            q.add(new Order(sc.nextInt(), sc.nextInt()));
        }

        solve(q);

        for(int i = 0; i < N; i++){
            System.out.print(line[i]+" ");
        }
        System.out.println();

    }

    public static void solve(Queue<Order> orders){
        while(!orders.isEmpty()){
            Order cur_order = orders.poll();
            int small_student = cur_order.first;
            int tall_student = cur_order.second;

            if(count == 0){
                is_choice[small_student] = true;
                is_choice[tall_student] = true;
                line[count++] = small_student;
                line[count++] = tall_student;
            }else{
                int small_index = -1;
                int tall_index = -1;
                for(int i = 0; i < count; i++){
                    if(line[i] == small_student){
                        small_index = i;
                    }
                    if(line[i] == tall_student){
                        tall_index = i;
                    }
                }

                if(small_index == -1 && tall_index == -1){
                    line[count++] = small_student;
                    is_choice[small_student] = true;
                    line[count++] = tall_student;
                    is_choice[tall_student] = true;
                }else if(small_index != -1 && tall_index == -1){
                    is_choice[tall_student] = true;
                    addLast(tall_student);
                }else if(small_index == -1 && tall_index != -1) {
                    is_choice[small_student] = true;
                    addFirst(small_student);
                }else if(small_index > tall_index){
                    swap(small_index, tall_index);
                }else if(small_index < tall_index){
                    continue;
                }
            }
        }
        for(int i = 1; i <= N; i++){
            if(is_choice[i] == false){
                addLast(i);
            }
        }
    }

    public static void addFirst(int a){
        for(int i = count+1; i >= 0; i--){
            line[i+1] = line[i];
        }
        count++;
        line[0] = a;
    }
    public static void addLast(int a){
        line[count++] = a;
    }
    public static void swap(int a, int b){
        int tmp = line[a];
        line[a] = line[b];
        line[b] = tmp;
    }
}

class Order{
    int first;
    int second;

    Order(int first, int second){
        this.first = first;
        this.second = second;
    }
}
