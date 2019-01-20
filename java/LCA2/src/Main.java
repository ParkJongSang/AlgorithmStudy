import java.util.*;

public class Main{
    static int N, M;
    static int parent[][];
    static int depth[];
    static int selected[];
    static ArrayList<Integer> order_list[];
    //static Queue<Integer> queue = new LinkedList<>();
    static Scanner sc = new Scanner(System.in);
    static ArrayList<Integer> ans = new ArrayList<>();
    public static void main(String[] args) {
        N = sc.nextInt();
        order_list = new ArrayList[N+1];
        selected = new int[N+1];
        parent = new int[20][N+1];
        depth = new int[N+1];
        Arrays.fill(selected, -1);
        for(int i = 0; i < 20; i++){
            Arrays.fill(parent[i], -1);
        }
        Arrays.fill(depth, -1);

        for(int i = 1; i < N+1; i++){
            order_list[i] = new ArrayList<>();
        }

        for(int i = 1; i < N; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            order_list[a].add(b);
            order_list[b].add(a);
        }

        //queue.add(1);
        selected[1] = 1;
        //int cur_depth = 0;


        //bfs
        //시간초과 난다. 다른방식으로 해야하나.
        //while(!queue.isEmpty()){
        //    int temp_size = queue.size();
        //    for(int i = 0; i < temp_size; i++){
        //        int start = queue.poll();
        //        for(int j = 0; j < order_list[start].size(); j++){
        //            if(selected[order_list[start].get(j)] != 1){
        //                queue.add(order_list[start].get(j));
        //                selected[order_list[start].get(j)] = 1;
        //                parent[order_list[start].get(j)] = start;
        //                depth[order_list[start].get(j)] = cur_depth;
        //            }
        //        }
        //    }
        //    cur_depth++;
        //}

        //dfs
        //역시 시간초과
        makeTree(1, 0);
        makeParent(parent);
        //여기까지 초기화... 초기화도 어렵다...
        M = sc.nextInt();

        for(int i = 0; i < M; i++){
            solve(sc.nextInt(), sc.nextInt());
            System.out.println(ans.get(i));
        }

    }

    public static void makeTree(int cur_vertex, int cur_depth){
        for(int i = 0; i < order_list[cur_vertex].size(); i++){
            if(selected[order_list[cur_vertex].get(i)] != 1){
                selected[order_list[cur_vertex].get(i)] = 1;
                makeTree(order_list[cur_vertex].get(i), cur_depth+1);
                parent[0][order_list[cur_vertex].get(i)] = cur_vertex;
                depth[order_list[cur_vertex].get(i)] = cur_depth;
            }
        }
    }

    public static void makeParent(int[][] parent){
        for(int i = 0; i < 20; i++){
            for(int j = 1; j < N+1; j++){
                if(parent[i][j] != -1){
                    parent[i+1][j] = parent[i][parent[i][j]];
                }
            }
        }
    }

    public static void solve(int a, int b){
        if(depth[a] < depth[b]){
           int temp = a;
           a = b;
           b = temp;
        }
        int diff = depth[a] - depth[b];



        for(int j = 0; diff != 0; j++){
            if(diff % 2 == 1) a = parent[j][a];
            diff /= 2;
        }

        if(a != b){
            for(int i = 19; i >= 0; i--){
                if(parent[i][a] != -1 && parent[i][a] != parent[i][b]){
                    a = parent[i][a];
                    b = parent[i][b];
                }
            }
            a = parent[0][a];
        }

        ans.add(a);
    }

    public static void depthSwap(int a, int b){
        int temp = depth[a];
        depth[a] = depth[b];
        depth[b] = temp;
    }
}