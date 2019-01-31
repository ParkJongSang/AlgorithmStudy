import java.util.Scanner;

public class Main {
    static int N;
    static long[] arr = new long[91];
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        arr[0] = 0; arr[1] = 1;
        for(int i = 2; i < 91; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }
        N = sc.nextInt();
        System.out.println(arr[N]);
    }
}
