import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    //그래프가 주어졌을 때, 단절점을 모두 구해 출력하는 프로그램을 작성하시오.
    //
    //단절점이란 그 정점을 제거했을 때, 그래프가 두 개 또는 그 이상으로 나누어지는 정점을 말한다. 즉, 제거했을 때 그래프의 connected component의 개수가 증가하는 정점을 말한다.

    //첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다.
    //다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이며, 방향은 양방향이다.
    //
    //입력으로 주어지는 그래프는 연결 그래프가 아닐 수도 있다.

    //첫째 줄에 단절점의 개수를 출력한다.
    //
    //둘째 줄에는 단절점의 번호를 공백으로 구분해 오름차순으로 출력한다.
    static Scanner sc = new Scanner(System.in);
    static int V, E;
    static ArrayList<Integer> links[] = new ArrayList[10001];
    static int discovered[] = new int[10001];
    static int discovered_order = 1;
    static boolean cut[] = new boolean[10001];
    static int count = 0;
    public static void main(String[] args) {
        //initialize
        V = sc.nextInt();
        E = sc.nextInt();

        for(int i = 1; i <= V; i++){
            links[i] = new ArrayList<>();
            discovered[i] = -1;
            cut[i] = false;
        }
        for(int i = 0; i < E; i++){
            int vertex_a = sc.nextInt();
            int vertex_b = sc.nextInt();
            links[vertex_a].add(vertex_b);
            links[vertex_b].add(vertex_a);
        }

        for(int i = 1; i <= V; i++){
            if(discovered[i] == -1){
                dfs(i, true);
            }
        }
        for(int i = 1; i <= V; i++){
            if(cut[i] == true){
               count++;
            }
        }
        System.out.println(count);

        for(int i = 1; i <= V; i++){
            if(cut[i] == true){
                System.out.print(i+" ");
            }
        }


    }

    public static int dfs(int here, boolean is_root){
        discovered[here] = discovered_order++;
        int to_retrun = discovered[here];
        int child = 0;

        for(int next :  links[here]){
            if(discovered[next] == -1){
                child++;
                int next_retrun = dfs(next, false);
                if(is_root == false && next_retrun >= discovered[here]) {
                    cut[here] = true;
                }
                to_retrun = Math.min(to_retrun, next_retrun);
            }else{
                to_retrun = Math.min(discovered[next], to_retrun);
            }
        }
        if(is_root == true && child > 1){
            cut[here] = true;
        }
        return to_retrun;
    }
}

