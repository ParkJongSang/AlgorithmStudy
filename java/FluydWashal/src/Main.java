import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int N, M;
    static int distance[][];
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();

        distance = new int[N+1][N+1];
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){

                if(i == j){
                    distance[i][j] = 0;
                }else{
                    distance[i][j] = 1000000000;
                }
            }
        }



        for(int i = 0; i < M; i++){
            int src = sc.nextInt();
            int dest = sc.nextInt();
            int weight = sc.nextInt();
            distance[src][dest] = Math.min(distance[src][dest], weight);
        }


        for(int k = 1; k < N+1; k++){
            for(int i = 1; i < N+1; i++){
                for(int j = 1; j < N+1; j++){
                    distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < N+1; j++){
                if(distance[i][j] != 1000000000) System.out.print(distance[i][j]+" ");
                 else System.out.print(0+" ");
             }
             System.out.println();
        }

    }
}
