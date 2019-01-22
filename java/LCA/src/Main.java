import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    //N(2 ≤ N ≤ 50,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.
    //
    //두 노드의 쌍 M(1 ≤ M ≤ 10,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.

    //첫째 줄에 노드의 개수 N이 주어지고, 다음 N-1개 줄에는 트리 상에서 연결된 두 정점이 주어진다.
    //그 다음 줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 주어지고, 다음 M개 줄에는 정점 쌍이 주어진다.

    //M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 공통 조상을 출력한다.
    static int N, M;
    static Scanner sc = new Scanner(System.in);
    static int visit[];
    static int depth[];
    static int parents[][];
    static ArrayList<Integer> links[];

    public static void main(String[] args) {
        N = sc.nextInt();

        visit = new int[N+1];
        depth = new int[N+1];
        parents = new int[N+1][20];
        links = new ArrayList[N+1];

        for(int i = 1; i < N+1; i++){
            links[i] = new ArrayList<>();
            visit[i] = -1;
            depth[i] = -1;
            Arrays.fill(parents[i], -1);
        }

        for(int i = 0; i < N-1; i++){
            int vertex_a = sc.nextInt();
            int vertex_b = sc.nextInt();
            links[vertex_a].add(vertex_b);
            links[vertex_b].add(vertex_a);
        }

        visit[1] = 1;
        depth[1] = 0;
        makeTreeByUsingDFS(1, 0);
        searchParentUsingDP(parents);
        M = sc.nextInt();

        while(M > 0){
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(LCA(a, b));
            M = M-1;
        }
    }

    public static void makeTreeByUsingDFS(int start, int cur_depth){
        for(int i = 0; i < links[start].size(); i++){
            int next = links[start].get(i);
            if(visit[next] == -1){
                visit[next] = 1;
                parents[next][0] = start;
                depth[next] = cur_depth+1;
                makeTreeByUsingDFS(next, cur_depth+1);
            }
        }
    }

    public static void searchParentUsingDP(int[][] parents){
        for(int i = 0; i < 19; i++){
            for(int j = 1; j < N+1; j++){
                if(parents[j][i] != -1){
                    parents[j][i+1] = parents[parents[j][i]][i];
                }
            }
        }
    }

    public static int LCA(int a, int b){
        if(depth[a] < depth[b]){
            int temp = a;
            a = b;
            b = temp;
        }

        int diff = depth[a] - depth[b];

        for(int i = 0; diff != 0; i++){
            if(diff%2 == 1) a = parents[a][i];
            diff /= 2;
        }

        if(a != b){
            for(int i = 19; i >= 0; i--){
                if(parents[a][i] != -1 && parents[a][i] != parents[b][i]){
                    a = parents[a][i];
                    b = parents[b][i];
                }
            }
            a = parents[a][0];
        }

        return a;
    }

}

