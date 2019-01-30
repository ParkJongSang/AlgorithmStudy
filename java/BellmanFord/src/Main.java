import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int N, M;
    static Scanner sc = new Scanner(System.in);
    static int distance[];
    static boolean flag = false;
    static ArrayList<Node> links = new ArrayList<>();

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();

        distance = new int[N+1];
        for(int i = 1; i < N+1 ; i++){
            distance[i] = Integer.MAX_VALUE;
        }

        for(int i = 0; i < M; i++){
            int src = sc.nextInt();
            int des = sc.nextInt();
            int weight = sc.nextInt();
            links.add(new Node(src, des, weight));
        }

        bellmanFord();

        if(flag == true){
            System.out.println(-1);
        }else{
            for(int i = 2; i < N+1; i++){
                if(distance[i] == Integer.MAX_VALUE) System.out.println(-1);
                else System.out.println(distance[i]);
            }
        }

    }

    public static void bellmanFord(){
        distance[1] = 0;
        for(int i = 0; i <= N; i++){
            for(int j = 0; j < M; j++){
                int src = links.get(j).src;
                int dest = links.get(j).dest;
                int weight = links.get(j).weight;
                if(distance[src] != Integer.MAX_VALUE && distance[dest] > distance[src] + weight){
                    distance[dest] = distance[src] + weight;
                    if(i == N) flag = true;
                }
            }
        }
    }
}
class Node{
    int src;
    int dest;
    int weight;

    Node(int src, int dest, int weight){
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}
