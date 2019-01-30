import java.util.Scanner;

public class Main {
    static final long MAX_VALUE = 1000000000;
    static Scanner sc = new Scanner(System.in);
    static int K, C;
    public static void main(String[] args) {

        int tc = sc.nextInt();

        while(tc > 0) {
            K = sc.nextInt();
            C = sc.nextInt();
            if (gcd(K, C) == Math.min(K, C)) {
                System.out.println("IMPOSSIBLE");
            } else if (K == 1) {
                System.out.println(C + 1);
            } else {
                //ax+by = 1;
                Tuple ans = solve(K, C);
                long t = Math.min(ceil(-ans.x, C), ceil(ans.y, K))-1;
                if(ans.y - MAX_VALUE > K * t){
                    System.out.println("IMPOSSIBLE");
                }else{
                    System.out.println(ans.y - K * t);
                }
            }
            tc--;
        }

    }

    public  static long ceil(long a, long b){
        if (a >= 0) {
            return (a+b-1)/b;
        }else{
            return a/b;
        }
    }

    //확장 유클리드 알고리즘
    public static Tuple solve(int a, int b){
        if (b == 0) {
            return new Tuple(a, 1, 0);
        }else{
            Tuple temp = solve(b, a%b);
            return new Tuple(temp.d, temp.y, temp.x - (a/b * temp.y));
        }
    }

    public static int gcd(int a, int b){
        if(b == 0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }

}
class Tuple{
    long d;
    long x;
    long y;

    Tuple(long d, long x, long y){
        this.d = d;
        this.x = x;
        this.y = y;
    }
}
