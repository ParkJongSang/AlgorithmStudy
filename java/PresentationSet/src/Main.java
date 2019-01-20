import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    //기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.
    //
    //집합을 표현하는 프로그램을 작성하시오.

    //첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다. m은 입력으로 주어지는 연산의 개수이다.
    //다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다.
    //이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다.
    //두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다.
    //이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다.
    //a와 b는 n 이하의 자연수또는 0이며 같을 수도 있다.

    static int N, M;
    static Queue<Order> order_list = new LinkedList<>();
    static Scanner sc = new Scanner(System.in);
    static int number_list[];
    static ArrayList<String> ans_list = new ArrayList<>();

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();
        number_list = new int[N+1];
        for(int i = 0; i < N+1; i++){
            number_list[i] = i;
        }

        for(int i = 0; i < M; i++){
            order_list.add(new Order(sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }

        solve(order_list);

        while(!ans_list.isEmpty()){
            System.out.println(ans_list.remove(0));
        }
    }
    public static void solve(Queue<Order> order_list){
        while (!order_list.isEmpty()){
            Order cur_order = order_list.poll();
            if(cur_order.order == 0){
                merge(cur_order.a, cur_order.b);
            }else{
                if(find(cur_order.a) == find(cur_order.b)){
                    ans_list.add("YES");
                }else{
                    ans_list.add("NO");
                }
            }
        }
    }

    public static int find(int n){
        if(number_list[n] == n)
            return n;
        else{
             return number_list[n] = find(number_list[n]);
        }
    }

    public static void merge(int a, int b){
        int set_a = find(a);
        int set_b = find(b);
        if(set_a == set_b) return;
        number_list[set_a] = set_b;
    }
}

class Order{
    int order;
    int a;
    int b;

    Order(int order, int a, int b){
        this.order = order;
        this.a = a;
        this.b = b;
    }
}