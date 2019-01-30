import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static int V, E;
    static ArrayList<Integer> links[];
    static int visited_road[];
    static Scanner sc = new Scanner(System.in);
    static int cur_visit_road = 1;
    static ArrayList<Two> ans = new ArrayList<>();
    public static void main(String[] args) {
        V = sc.nextInt();
        E = sc.nextInt();

        links = new ArrayList[V+1];
        visited_road = new int[V+1];
        Arrays.fill(visited_road, -1);
        for(int i = 1; i < V+1; i++){
            links[i] = new ArrayList<>();

        }

        for(int i = 0; i < E; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            links[a].add(b);
            links[b].add(a);
        }

        for(int i = 1; i < V+1; i++){
            if(visited_road[i] == -1){
                dfsToFindCutRoad(1, 0);
            }
        }
        Collections.sort(ans);
        System.out.println(ans.size());
        while(!ans.isEmpty()){
            Two temp  = ans.remove(0);
            System.out.println(temp.min+" "+temp.max);
        }

    }
    public static int dfsToFindCutRoad(int start, int parent){
        visited_road[start] = cur_visit_road++;

        int to_return = visited_road[start];

        for(int next : links[start]){
            if(next == parent){
                continue;
            }
            if(visited_road[next] == -1){
                int next_visit = dfsToFindCutRoad(next, start);

                if(next_visit > visited_road[start]){
                    ans.add(new Two(Math.min(start, next), Math.max(start, next)));
                }
                to_return = Math.min(next_visit, to_return);
            }else{
                to_return = Math.min(visited_road[next], to_return);
            }
        }
        return to_return;
    }

}
class Two implements Comparable<Two>{
    int min;
    int max;
    Two(int min, int max){
        this.min = min;
        this.max = max;
    }

    @Override
    public int compareTo(Two o) {
        if(this.min == o.min){
            return this.max - o.max;
        }else{
            return this.min - o.min;
        }
    }
}
