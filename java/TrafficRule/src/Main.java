import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // 첫째 줄에 도시의 개수 N과 도로의 개수 E가 주어진다.
    // (2 ≤ N ≤ 100,000, 1 ≤ E ≤ 500,000) 이어서 E개의 줄에 걸쳐 각 줄에 N 이하의 서로 다른 두 자연수가 주어지는데,
    // 이는 두 자연수를 번호로 하는 두 개의 도시 사이에 도로가 존재함을 의미한다.
    // 같은 도로가 여러 번 입력으로 주어지지 않으며, 임의의 두 도시 사이에 항상 이동할 수 있는 경로가 하나 이상 존재하는 교통 체계만이 입력으로 주어진다.
    //
    // 다음 줄에는 질문의 개수 Q가 주어진다. (1 ≤ Q ≤ 300,000) 이어서 Q개의 줄에 걸쳐 질문에 대한 정보가 주어지는데,
    // 각 줄의 첫 번째 자연수는 질문의 유형을 나타내는 1 또는 2이다.
    // 질문이 유형 1에 해당하는 경우는 N 이하의 네 개의 자연수 A, B, G1, G2가 순서대로 주어진다.
    // A와 B는 서로 다르며, G1과 G2 사이에 항상 도로가 존재하는 경우만이 입력으로 주어진다.
    // 질문이 유형 2에 해당하는 경우는 N 이하의 서로 다른 자연수 A, B, C가 순서대로 주어진다.
    // Q개의 줄에 걸쳐 각 질문에 대한 답을 한 줄에 하나씩 yes나 no로 출력한다.
    // 질문의 답이 "이동할 수 있다"이면 yes를, "이동할 수 없다"이면 no를 출력하면 된다.
    static int N, E, Q;
    static int visited_vertex[];
    static ArrayList<Integer> links[];
    static int visited_road[][];
    static Scanner sc = new Scanner(System.in);
    static int cur_visit_vertex = 1;
    static int cur_visit_road = 1;
    static boolean is_cut_point[];
    public static void main(String[] args) {
        N = sc.nextInt();
        E = sc.nextInt();

        visited_vertex = new int[N+1];
        visited_road = new int[N+1][N+1];
        is_cut_point = new boolean[N+1];
        is_cut_road = new boolean[N+1][N+1];

        links = new ArrayList[N+1];

        for(int i = 1; i < N+1; i++){
            links[i] = new ArrayList<>();
            Arrays.fill(visited_road[i], -1);
            Arrays.fill(is_cut_road[i], false);
        }

        Arrays.fill(visited_vertex, -1);
        Arrays.fill(is_cut_point, false);

        for(int i = 0; i < E; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            links[a].add(b);
            links[b].add(a);
        }

        for(int i = 1; i < N+1; i++){
            if(visited_vertex[i] == -1){
                dfsToFindCutVertex(i, true);
            }
        }
        for(int i = 1; i < N+1; i++){
            for(int j : links[i]){
                if(visited_road[i][j] == -1){
                    dfsToFindCutRoad(j, i);
                }
            }
        }

        Q = sc.nextInt();

        while(Q > 0){
            int q = sc.nextInt();
            if(q == 1){
                int a = sc.nextInt();
                int b = sc.nextInt();
                int c = sc.nextInt();
                int d = sc.nextInt();



            }else if(q == 2){
                int a = sc.nextInt();
                int b = sc.nextInt();
                int c = sc.nextInt();
            }
        }
    }

    public static int dfsToFindCutVertex(int start, boolean is_root){
        visited_vertex[start] = cur_visit_vertex++;
        int to_return =visited_vertex[start];
        int child = 0;

        for(int next : links[start]){
            if(visited_vertex[next] == -1){
                child++;
                int next_visit = dfsToFindCutVertex(next, false);
                if(is_root == false && to_return <= next_visit){
                    is_cut_point[start] = true;
                }
                to_return = Math.min(to_return, next_visit);
            }else{
                to_return = Math.min(to_return, visited_vertex[next]);
            }
        }

        if(is_root == true && child > 1){
            is_cut_point[start] = true;
        }
        return to_return;
    }

    public static int dfsToFindCutRoad(int start, int parent){
        visited_road[parent][start] = cur_visit_road;
        visited_road[start][parent] = cur_visit_road++;

        int to_return = visited_road[parent][start];

        for(int next: links[start]){
            if(visited_road[start][next] == -1){
                int next_visit = dfsToFindCutRoad(next, start);
                if(next_visit >= visited_road[start][next]){
                    is_cut_road[start][next] = true;
                    is_cut_road[next][start] = true;
                }
                to_return = Math.min(next_visit, to_return);
            }else{
                to_return = Math.min(visited_road[start][next], to_return);
            }
        }
        return to_return;
    }
}
