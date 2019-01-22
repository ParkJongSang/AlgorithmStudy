import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    //첫째 줄에 N이 주어진다. (2 ≤ N ≤ 100,000)
    //
    //다음 N-1개 줄에는 도로를 나타내는 세 정수 A, B, C가 주어진다. A와 B사이에 길이가 C인 도로가 있다는 뜻이다. 도로의 길이는 1,000,000보다 작거나 같은 양의 정수이다.
    //
    //다음 줄에는 K가 주어진다. (1 ≤ K ≤ 100,000)
    //
    //다음 K개 줄에는 서로 다른 두 자연수 D와 E가 주어진다. D와 E를 연결하는 경로에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구해서 출력하면 된다
    static int N, K;
    static Scanner sc = new Scanner(System.in);
    static ArrayList<Node> links[];
    static Queue<Order> q = new LinkedList<>();
    static int parents[][];
    static int depth[];
    static int visit[];
    static int min[][];
    static int max[][];

    public static void main(String[] args) {
        //initialize
        N = sc.nextInt();

        links = new ArrayList[N+1];
        parents = new int[N+1][20];
        depth = new int[N+1];
        visit = new int[N+1];
        min = new int[N+1][20];
        max = new int[N+1][20];

        for(int i = 1; i < N+1; i++){
            for(int j = 0; j < 20; j++){
                min[i][j] = Integer.MAX_VALUE;
                max[i][j] = Integer.MIN_VALUE;
            }
        }

        for(int i = 1; i < N+1; i++){
            links[i] = new ArrayList<>();
        }

        for(int i = 1; i < N; i++){
            int vertex_a = sc.nextInt();
            int vertex_b = sc.nextInt();
            int length = sc.nextInt();
            links[vertex_a].add(new Node(vertex_b, length));
            links[vertex_b].add(new Node(vertex_a, length));
        }
        K = sc.nextInt();

        for(int i = 0; i < K; i++){
            int vertex_a = sc.nextInt();
            int vertex_b = sc.nextInt();
            q.add(new Order(vertex_a, vertex_b));
        }

        visit[1] = 1;

        makeTreeByUsingDFS(1, 0);

        memorizeParentsAndLongestAndShortestRoadByDynamicProgramming(parents, max, min);

        while(!q.isEmpty()){
            Order poll = q.poll();
            MaxMin temp = serachLongestAndShortestLength(poll.a, poll.b);
            System.out.println(temp.min+" "+temp.max);
        }
    }

    public static void makeTreeByUsingDFS(int cur_vertex, int cur_depth){
        for(int i = 0; i < links[cur_vertex].size(); i++){
            if(visit[links[cur_vertex].get(i).vertex] != 1){
                Node temp = links[cur_vertex].get(i);
                visit[temp.vertex] = 1;
                makeTreeByUsingDFS(temp.vertex, cur_depth+1);
                depth[temp.vertex] = cur_depth+1;
                parents[temp.vertex][0] = cur_vertex;
                min[temp.vertex][0] = links[cur_vertex].get(i).length;
                max[temp.vertex][0] = links[cur_vertex].get(i).length;
            }
        }
    }

    public static MaxMin serachLongestAndShortestLength(int a, int b){
        int cur_min = Integer.MAX_VALUE;
        int cur_max = Integer.MIN_VALUE;

        if(depth[a] < depth[b]){
            int temp = a;
            a = b;
            b = temp;
        }

        int diff = depth[a] - depth[b];

        for(int i = 0; diff != 0 ; i++){
            if(diff%2 == 1) {
                cur_min = Math.min(cur_min, min[a][i]);
                cur_max = Math.max(cur_max, max[a][i]);
                a = parents[a][i];

            }
            diff /= 2;
        }

        if(a != b){
            for(int i = 19; i >= 0; i--){
                if(parents[a][i] != -1 && parents[a][i] != parents[b][i]){
                    cur_min = Math.min(cur_min, min[a][i]);
                    cur_max = Math.max(cur_max, max[a][i]);
                    a = parents[a][i];
                    cur_min = Math.min(cur_min, min[b][i]);
                    cur_max = Math.max(cur_max, max[b][i]);
                    b = parents[b][i];
                }
            }
            cur_min = Math.min(cur_min, Math.min(min[a][0],min[b][0]));
            cur_max = Math.max(cur_max, Math.max(max[a][0],max[b][0]));
        }

        return new MaxMin(cur_max, cur_min);
    }

    public static void memorizeParentsAndLongestAndShortestRoadByDynamicProgramming(int parents[][], int max[][], int min[][]){
        for(int i = 0; i < 19; i++){
            for(int j = 1; j < N+1; j++){
                if(parents[j][i] != 0){
                    parents[j][i+1] = parents[parents[j][i]][i];
                }
                if(max[j][i] != Integer.MIN_VALUE){
                    max[j][i+1] = Math.max(max[j][i], max[parents[j][i]][i]);
                }
                if(min[j][i] != Integer.MAX_VALUE){
                    min[j][i+1] = Math.min(min[j][i], min[parents[j][i]][i]);
                }
            }
        }
    }

}
class MaxMin{
    int max;
    int min;
    MaxMin(int max, int min){
        this.max = max;
        this.min = min;
    }
}

class Order{
    int a;
    int b;
    Order(int a, int b){
        this.a = a;
        this.b = b;
    }
}

class Node{
    int vertex;
    int length;

    Node(int vertex, int length){
        this.vertex = vertex;
        this.length = length;
    }
}

