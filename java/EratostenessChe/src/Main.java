import java.util.Scanner;

public class Main {
    static int N, K;
    static Scanner sc = new Scanner(System.in);
    static int[] arr = new int[1001];
    public static void main(String[] args) {
        N = sc.nextInt();K = sc.nextInt();
        for(int i = 2; i <= N; i++){
            arr[i] = i;
        }

        System.out.println(solve());

    }

    public static int solve(){
        int ret = 0;
        for(int i = 2; i <= N; i++){
            if(arr[i] == 0){
                continue;
            }else{
                int j = i;
                while(j <= N && ret < K){
                    if(arr[j] != 0){
                        ret++;
                        if(ret == K){
                            return arr[j];
                        }
                        arr[j] = 0;
                    }
                    j += i;
                }
            }
        }
        return -1;
    }
}
