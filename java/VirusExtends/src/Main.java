import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int N, M;
    static int map[][];
    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};
    static ArrayList<Point> can_build_wall_list = new ArrayList<>();
    static ArrayList<Point> virus_pos_list = new ArrayList<>();

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N][M];
        int ans = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                map[i][j] = sc.nextInt();
                if(map[i][j] == 0){
                    can_build_wall_list.add(new Point(i,j));
                }
                if(map[i][j] == 2){
                    virus_pos_list.add(new Point(i,j));
                }
            }
        }

        for(int i = 0; i < can_build_wall_list.size() - 2; i++){
            for(int j = i+1; j < can_build_wall_list.size() - 1; j++){
                for(int k = j+1; k < can_build_wall_list.size(); k++){
                    Point first_wall = can_build_wall_list.get(i);
                    Point second_wall = can_build_wall_list.get(j);
                    Point third_wall = can_build_wall_list.get(k);

                    int[][] copy_map = new int[N][M];

                    clone(copy_map, map);

                    copy_map[first_wall.x][first_wall.y] = 1;
                    copy_map[second_wall.x][second_wall.y] = 1;
                    copy_map[third_wall.x][third_wall.y] = 1;

                    extendVirus(copy_map, virus_pos_list);

                    ans = Math.max(ans, countFree(copy_map));
                }
            }
        }

        System.out.println(ans);
    }

    public static int countFree(int[][] map){
        int count = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }

    public static void extendVirus(int[][] map, ArrayList<Point> virus_pos_list){
        for(int i = 0; i < virus_pos_list.size(); i++){
            dfs(map, virus_pos_list.get(i).x, virus_pos_list.get(i).y);
        }
    }

    public static void dfs(int[][] map,int x, int y){
        for(int i = 0; i < 4; i++){
            if(isInside(x+dx[i], y+dy[i])){
                if(map[x+dx[i]][y+dy[i]] == 0){
                    map[x+dx[i]][y+dy[i]] = 2;
                    dfs(map, x+dx[i], y+dy[i]);
                }
            }
        }
    }

    public static boolean isInside(int x, int y){
        return (x >= 0 && x < N) && (y >= 0 && y < M);
    }

    public static void clone(int[][] arr_a, int[][] arr_b){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                arr_a[i][j] = arr_b[i][j];
            }
        }
    }
}

class Point{
    int x;
    int y;
    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}