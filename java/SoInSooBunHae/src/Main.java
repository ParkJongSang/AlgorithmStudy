import java.util.Scanner;

public class Main {
    static final int MAX_VALUE = 10000001;
    static int N;
    static int prime[] = new int[MAX_VALUE];
    static int number[] = new int[MAX_VALUE];
    static Scanner sc = new Scanner(System.in);
    static int c = 0;

    public static void main(String[] args) {
        for(int i = 0; i < MAX_VALUE; i++){
            number[i] = i;
            prime[i] = 0;
        }

        for(int i = 2; i < MAX_VALUE; i++){
            if(number[i] == 0){
                continue;
            }else{
                prime[c++] = i;
                int j = i + i;
                while(j < MAX_VALUE){
                    if(number[j] != 0){
                        number[j] = 0;
                    }
                    j += i;
                }
            }
        }

        N = sc.nextInt();

        solve(N);
    }

    public static void solve(int n){
        int idx = 0;
        while(n != 1 && idx < c){
            if(n % prime[idx] == 0){
                n = n / prime[idx];
                System.out.println(prime[idx]);
            }else{
                idx++;
            }
        }
    }
}
