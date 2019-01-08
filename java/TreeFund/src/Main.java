/**
 * 백준 알고리즘 16235번문제
 *
 * 나무 재테크
 *
 * LinkedList로는 시간초과였지만 ArrayList로는 발생하지 않았다.
 *
 * For문이 많아서 그런줄 알았으나 자료구조의 차이로도 성능차이가 발생한다는 것을 알게됨.
 *
 * 허나 삽입 삭제에서는 LinkedList가 유리한것으로 알고 있는데
 *
 * 왜 ArrayList일때 통과가 되었는가.
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    final static int[][] adjecent = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    static int N;
    static int M;
    static int K;
    static ArrayList<Integer>[][] ground;
    static int ans;

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        ans = 0;
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        ground= new ArrayList[N+1][N+1];
        int[][] A = new int[N+1][N+1];
        int[][] feed = new int[N+1][N+1];

        for(int i = 1; i < feed.length; i++){
            for(int j = 1; j < feed.length; j++){
                ground[i][j] = new ArrayList<>();
                feed[i][j] = 5;
                A[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < M; i++){
            int tree_x = sc.nextInt();
            int tree_y = sc.nextInt();
            int tree_year = sc.nextInt();
            ground[tree_x][tree_y].add(tree_year);
            ans++;
        }

        for(int k = 0; k < K; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++) {
                    if(ground[i][j].size() != 0){
                        Collections.sort(ground[i][j]);
                        int diedFeed = 0;
                        for (int a = 0; a < ground[i][j].size(); a++) {
                            if (feed[i][j] >= ground[i][j].get(a)) {
                                //봄
                                feed[i][j] -= ground[i][j].get(a);
                                ground[i][j].add(a, ground[i][j].remove(a) + 1);
                            } else {
                                //여름
                                diedFeed += ground[i][j].remove(a) / 2;
                                a--;
                                ans--;
                            }
                        }
                        feed[i][j] += diedFeed;
                    }else{
                        continue;
                    }

                }
            }

            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++) {
                    //가을
                    int toGrow = isGrow(ground[i][j]);
                    if(toGrow > 0){
                        for(int a = 0; a < 8; a++){
                            int new_x = i + adjecent[a][0];
                            int new_y = j + adjecent[a][1];
                            if(isInside(new_x, new_y)){
                                for(int c = 0; c < toGrow; c++){
                                    ans++;
                                    ground[new_x][new_y].add(1);
                                }
                            }

                        }
                    }
                    //겨울
                    feed[i][j] += A[i][j];
                }
            }

        }
        System.out.println(ans);

    }

    public static int isGrow(ArrayList<Integer> pq){
        //LinkedList<Integer> temp = pq;
        int count = 0;
        for(int i = 0; i < pq.size(); i++){
            if(pq.get(i) % 5 == 0) count++;
        }
        return count;
    }

    public static boolean isInside(int a, int b){
        return (a >= 1 && a < N+1) && (b >= 1 && b < N+1);
    }
}
