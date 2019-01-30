import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static final int MAX = 1000001;
    static BigInteger P;
    static int K;
    static int number[] = new int[MAX];
    static int prime[] = new int[MAX];
    static int c = 0;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        for(int i = 0; i < MAX; i++){
            prime[i] = 0;
            number[i] = i;
        }

        for(int i = 2; i < MAX; i++){
            if(number[i] == 0){
                continue;
            }else{
                prime[c++] = i;
                int j = i+i;
                while (j < MAX){
                    number[j] = 0;
                    j += i;
                }
            }
        }
        P = sc.nextBigInteger();
        K = sc.nextInt();

        solve(P, K);

    }

    public static void solve(BigInteger P, int K){
        int idx = 0;

        while(idx < c){
            BigInteger temp = new BigInteger(prime[idx]+"");
            if(P.remainder(temp).equals(BigInteger.ZERO)){
                BigInteger a = new BigInteger(prime[idx]+"");
                if(a.compareTo(BigInteger.valueOf(K)) == -1){
                    System.out.println("BAD " + a);
                    return;
                }
            }
            idx++;
        }

        System.out.println("GOOD");
    }
}
