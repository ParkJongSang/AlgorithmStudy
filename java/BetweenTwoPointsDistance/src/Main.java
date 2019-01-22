import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    //N(2≤N≤40,000)개의 정점으로 이루어진 트리가 주어지고 M(M≤10,000)개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.
    static int N, M;
    static int parent[][];
    static int visit[];
    static int depth[];
    static int distance[][];
    static ArrayList<Link> links[];
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        N = sc.nextInt();
        parent = new int[N+1][20];
        visit = new int[N+1];
        depth = new int[N+1];
        links = new ArrayList[N+1];
        distance = new int[N+1][20];
        for(int i = 1; i < N+1; i++){
            Arrays.fill(parent[i], -1);
            Arrays.fill(distance[i], 0);
            visit[i] = -1;
            depth[i] = -1;
            links[i] = new ArrayList<>();
        }

        for(int i = 0; i < N-1; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            links[u].add(new Link(v, w));
            links[v].add(new Link(u, w));
        }
        visit[1] = 1;
        depth[1] = 0;
        makeTreeByUsingDFS(1, 0);
        searchParentByDP(parent, distance);

        M = sc.nextInt();

        while(M > 0){
            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println(calcDistanceByLCA(a, b));
            M--;
        }
    }

    public static void makeTreeByUsingDFS(int start, int cur_depth){
        for(int i = 0; i < links[start].size(); i++){
            Link temp = links[start].get(i);
            if(visit[temp.vertex] != 1){
                visit[temp.vertex] = 1;
                depth[temp.vertex] = cur_depth+1;
                parent[temp.vertex][0] = start;
                distance[temp.vertex][0] = temp.distance;
                makeTreeByUsingDFS(temp.vertex, cur_depth+1);
            }
        }
    }

    public static void searchParentByDP(int parent[][], int distance[][]){
        for(int i = 0; i < 19; i++){
            for(int j = 1; j < N+1; j++){
                if(parent[j][i] != -1){
                    parent[j][i+1] = parent[parent[j][i]][i];
                    distance[j][i+1] = distance[j][i] + distance[parent[j][i]][i];
                }
            }
        }
    }

    public static int calcDistanceByLCA(int a, int b){
        int cur_distance = 0;
        if(depth[a] < depth[b]){
            int temp = a;
            a = b;
            b = temp;
        }

        int diff = depth[a] - depth[b];

        for(int i = 0; diff != 0; i++){
            if(diff%2 == 1){
                cur_distance += distance[a][i];
                a = parent[a][i];
            }
            diff /= 2;
        }

        if(a != b){
            for(int i = 19; i >= 0; i--){
                if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
                    cur_distance = cur_distance + distance[a][i] + distance[b][i];
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            cur_distance = cur_distance + distance[a][0] + distance[b][0];
        }
        return cur_distance;
    }
}

class Link{
    int vertex;
    int distance;

    Link(int vertex, int distance){
        this.vertex = vertex;
        this.distance = distance;
    }
}
