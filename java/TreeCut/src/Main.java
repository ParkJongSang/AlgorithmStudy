import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int N;
    static long M;
    static long trees[];
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        N = sc.nextInt(); M = sc.nextLong();
        trees = new long[N];

        for(int i = 0; i < N; i++){
            trees[i] = sc.nextLong();
        }

        Arrays.sort(trees);

        solve(M);

    }

    public static void solve(long m){
        long start = 0;
        long end = trees[N-1];
        long sum;
        long cut_point;
        long max = 0;
        while(start <= end){
            sum = 0;
            cut_point = (start+end)/2;

            for(int i = N-1; i >= 0; i--){
                if(trees[i] > cut_point){
                    sum = sum + trees[i] - cut_point;
                }else{
                    break;
                }
            }

            if(sum >= m){
                max = Math.max(max, cut_point);
                start = cut_point + 1;
            }else{
                end = cut_point - 1;
            }
        }

        System.out.println(max);
    }
}
