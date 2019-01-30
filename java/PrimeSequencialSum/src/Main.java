import java.util.Scanner;

public class Main {
    static int N;
    static final int MAX_SIZE = 4000001;
    static int prime[] = new int[MAX_SIZE];
    static int number[] = new int[MAX_SIZE];
    static Scanner sc = new Scanner(System.in);
    static int c = 0;
    public static void main(String[] args) {
        N = sc.nextInt();
        for(int i = 2; i < MAX_SIZE; i++){
            prime[i] = 0;
            number[i] = i;
        }

        for(int i = 2; i < MAX_SIZE; i++){
            if(number[i] == 0){
                continue;
            }else{
                prime[c++] = i;
                int j = i + i;
                while(j < MAX_SIZE){
                    number[j] = 0;
                    j += i;
                }
            }
        }

        System.out.println(solve(N));
    }


    public static int solve(int n){
        int ret = 0;
        for(int i = 0; i < c; i++){
            int j = i + 1;
            int sum = prime[i];
            while(j < MAX_SIZE && sum < n){
                sum += prime[j];
                j += 1;
            }
            if(sum == n){
                ret += 1;
            }

        }
        return ret;
    }
}
