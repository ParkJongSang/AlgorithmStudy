import java.util.*;

public class Main {
    //첫째 줄에 컴퓨터의 수 N (1 ≤ N ≤ 1000)가 주어진다.
    //
    //둘째 줄에는 연결할 수 있는 선의 수 M (1 ≤ M ≤ 100,000)가 주어진다.
    //
    //셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다.
    //이 비용의 정보는 세 개의 정수로 주어지는데, 만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c (1 ≤ c ≤ 10,000) 만큼 든다는 것을 의미한다.

    //모든 컴퓨터를 연결하는데 필요한 최소비용을 첫째 줄에 출력한다.

    static int N, M;
    static Link[] links;
    static PriorityQueue<Link> pq = new PriorityQueue<>();
    static Scanner sc = new Scanner(System.in);
    static int is_merged[];
    static int ans = 0;
    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();

        is_merged = new int[N+1];
        for(int i = 1; i < N+1; i++){
            is_merged[i] = -1;
        }
        links = new Link[M];
        for(int i = 0; i < M; i++){
            links[i] = new Link();
            links[i].vertex_a = sc.nextInt();
            links[i].vertex_b = sc.nextInt();
            links[i].distance = sc.nextInt();
            pq.add(links[i]);
        }

        mst(pq);

        System.out.println(ans);
    }
    public static int find(int n){
        if(is_merged[n] == -1){
            return n;
        }else{
            return n = find(is_merged[n]);
        }
    }
    public static boolean union(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x == y) return false;
        is_merged[y] = x;
        return true;
    }

    public static void mst(PriorityQueue<Link> pq){
        int connected_edges = 0;
        while(!pq.isEmpty()){
            Link temp = pq.poll();
            if(union(temp.vertex_a, temp.vertex_b)){
                connected_edges++;
                ans+=temp.distance;
            }
            if(connected_edges == N-1){
                break;
            }
        }
    }
}
class Link implements Comparable<Link> {
    int vertex_a;
    int vertex_b;
    int distance;

    @Override
    public int compareTo(Link o) {
        return this.distance - o.distance;
    }
}