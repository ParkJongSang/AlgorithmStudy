import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static ArrayList<Integer> list = new ArrayList<>();
    static Queue<Pair> q = new LinkedList<>();
    static Scanner sc = new Scanner(System.in);
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int[][] visit;
    static int num;
    static int count;

    public static void main(String[] args) {
        N = sc.nextInt();
        map = new int[N][N];
        visit = new int[N][N];
        num = 0;

        for(int i = 0; i < N; i++){
            String temp = sc.next();
            for(int j = 0; j < N; j++){
                map[i][j]= temp.charAt(j)-'0';
                visit[i][j] = 0;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] != 0 && visit[i][j] == 0){
                    count++;
                    num = 0;
                    bfs(i,j);
                    list.add(num);
                }
            }
        }

        Collections.sort(list);

        System.out.println(count);
        for(int i = 0; i < list.size(); i++){
            System.out.println(list.get(i));
        }

    }

    public static void bfs(int x, int y){
        Pair temp = new Pair();
        temp.x = x;
        temp.y = y;

        q.add(temp);
        visit[x][y] = 1;

        while(!q.isEmpty()){
            Pair pop = q.poll();
            num++;
            for(int i = 0; i < 4; i++){
                int next_x = pop.x + dx[i];
                int next_y = pop.y + dy[i];
                if(isInside(next_x, next_y) && map[next_x][next_y] == 1 && visit[next_x][next_y] ==0){
                    Pair toAdd = new Pair();
                    toAdd.x = next_x;
                    toAdd.y = next_y;
                    visit[next_x][next_y] = 1;
                    q.add(toAdd);
                }
            }
        }
    }

    public static boolean isInside(int x, int y){
        return (x >= 0 && x < N) && (y >= 0 && y < N);
    }
}
class Pair{
    int x;
    int y;
}
