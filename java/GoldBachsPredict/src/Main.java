import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int N;
    static Scanner sc = new Scanner(System.in);
    static final int MAX_SIZE = 1000001;
    static int[] prime = new int[MAX_SIZE];
    static int[] arr = new int[MAX_SIZE];
    static int c = 0;
    public static void main(String[] args) {
        for(int i = 2; i < MAX_SIZE; i++){
            arr[i] = i;
        }
        makePrime();
        while(true){
            N = sc.nextInt();
            if(N == 0){
                break;
            }
            solve(N);
        }
    }

    public static void makePrime(){

        for(int i = 2; i < MAX_SIZE; i++){
            if(arr[i] == 0){
               continue;
            }else{
                prime[c++] = i;
                int j = i+i;
                while(j < MAX_SIZE){
                    if(arr[j] != 0){
                        arr[j] = 0;
                    }
                    j += i;
                }
            }
        }
    }

    public static void solve(int n){
        ArrayList<Integer> temp = new ArrayList<>();
        int i = 0;

        for(int idx = 0; idx < c/2; idx++){
            int a = prime[idx];
            int b = n - a;
            if(arr[b] == 0){
                continue;
            }else{
                System.out.println(n + " = " + a + " + " + b);
                return;
            }
        }

        System.out.println("Goldbach's conjecture is wrong.");
    }
}
