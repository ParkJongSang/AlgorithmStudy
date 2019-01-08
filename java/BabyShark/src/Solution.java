import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

/*
*백준 아기상어 문제
*
*DFS로 풀려 했다가 낭패를 보고 BFS로 회선변경한 문제
*
* 1. 이동할수 있는 경로와 비용 탐색
*
* 2. 가장 가까운 먹이로 이동
*
* 3. 1~2를 먹을수있는 먹이가 없을때까지 반복
 */

public class Solution {
    static int size;
    static int sharkSize = 2;
    static int[][] map;
    static int eat = 0;
    static int[] fishes = new int[7];
    static int shark_x, shark_y;
    static Scanner sc = new Scanner(System.in);
    static int[][] dis;
    static int[][] visit;
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    static PriorityQueue<Point> pq = new PriorityQueue<>();
    static int answer;


    public static void main(String[] args) {
        answer = 0;
        size = sc.nextInt();
        map = new int[size][size];
        dis = new int[size][size];
        visit = new int[size][size];

        for(int i = 0; i < fishes.length; i++){
            fishes[i] = 0;
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                map[i][j] = sc.nextInt();
                if(map[i][j] > 0 && map[i][j] < 9){
                    fishes[map[i][j]]++;
                }
                if(map[i][j] == 9){
                    shark_x = i;
                    shark_y = j;
                }
            }
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++) {
                dis[i][j] = -1;
                visit[i][j] = 0;
            }
        }

        bfs(map,shark_x,shark_y);
        map[shark_x][shark_y] = 0;
        while(!pq.isEmpty()){

            Point temp = pq.poll();
            answer += temp.dis;
            eat++;
            map[temp.x][temp.y] = 0;
            if(sharkSize == eat){
                sharkSize++;
                eat = 0;
            }

            bfs(map, temp.x, temp.y);
        }

        System.out.println(answer);
    }

    public static void bfs(int[][] map, int x, int y){

        Queue<Point> points = new LinkedList<>();;
        pq.clear();
        points.add(new Point(x, y));

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                dis[i][j] = -1;
            }
        }

        dis[x][y] = 0;

        while(!points.isEmpty()){
            int cur_x = points.peek().x;
            int cur_y = points.peek().y;
            points.poll();

            for(int i = 0; i < 4; i++){
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];

                if(isInside(next_x, next_y) && dis[next_x][next_y] == -1 && map[next_x][next_y] <= sharkSize){
                    dis[next_x][next_y] = dis[cur_x][cur_y] + 1;

                    if(map[next_x][next_y] != 0 && map[next_x][next_y] < sharkSize){
                        pq.add(new Point(next_x,next_y,dis[next_x][next_y]));
                    }

                    points.add(new Point(next_x, next_y));
                }
            }
        }

    }

    public static boolean isInside(int a, int b){
        return (a < size && a >= 0) && (b < size && b >= 0);
    }

    public static boolean isEatable(){
        boolean result = false;
        for(int i =0 ; i < sharkSize; i++){
            if(fishes[i] > 0) {
                result = true;
                break;
            }
        }
        return result;
    }
}

class Point implements Comparable<Point>{
    int x, y, dis;

    Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    Point(int x, int y, int dis){
        this.x = x;
        this.y = y;
        this.dis = dis;
    }

    @Override
    public int compareTo(Point o) {
        if(this.dis == o.dis){
            if(this.x == o.x)
                return this.y - o.y;
            return this.x - o.x;
        }
        return this.dis - o.dis;
    }
}
