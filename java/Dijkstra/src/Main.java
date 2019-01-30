import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int V, E;
    static int distance[];
    static ArrayList<Node> links[];
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        int start_vertex = Integer.parseInt(br.readLine());

        links = new ArrayList[V+1];
        distance = new int[V+1];

        for(int i = 1; i < V+1; i++){
            links[i] = new ArrayList<>();
            distance[i] = Integer.MAX_VALUE;
        }

        for (int e = 0; e < E; ++e) { // 간선들을 저장합니다.
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            links[from].add(new Node(to, cost));
        }

        dijkstra(start_vertex);

        for(int i = 1; i < distance.length; i++){
            if(distance[i] == Integer.MAX_VALUE) System.out.print("INF\n");
            else System.out.print(distance[i]+"\n");
        }

        sc.close();
    }

    public static void dijkstra(int start){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        distance[start] = 0;

        while(!pq.isEmpty()){
            Node next_vertex = pq.poll();
            ArrayList<Node> al = links[next_vertex.vertex];
            for(int i = 0; i < al.size(); i++){
                Node temp = al.get(i);
                int calc_temp = distance[next_vertex.vertex] + temp.distance;
                //다익스트라에서 우선순위큐에 들어가는 것은 temp.distance가 아닌
                //distance[temp.vertex]
                if(distance[temp.vertex] > calc_temp){
                    distance[temp.vertex] = calc_temp;
                    pq.offer(new Node(temp.vertex, distance[temp.vertex]));
                }
            }
        }
    }

}

class Node implements Comparable<Node>{
    int vertex;
    int distance;

    Node(int vertex, int distance){
        this.vertex = vertex;
        this.distance = distance;
    }

    @Override
    public int compareTo(Node o) {
        return this.distance - o.distance;
    }
}
