import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int VN;
    static int EN;
    static LinkedList<Integer>[] list;
    static int[] visit;
    static int ans;

    public static void main(String[] args) {
        VN = sc.nextInt();
        EN = sc.nextInt();
        ans = 0;

        list = new LinkedList[VN+1];
        visit = new int[VN+1];
        for(int i = 0; i <= VN; i++){
            list[i] = new LinkedList<>();
            visit[i] = 0;
        }

        for(int i = 1; i <= EN; i++){
            int start = sc.nextInt();
            int end = sc.nextByte();
            list[start].add(end);
            list[end].add(start);
        }

        dfs(1);

        System.out.println(ans-1);
    }

    public static void dfs(int vertex){
        if(visit[vertex] == 1)
            return;
        else{
            visit[vertex] = 1;
            ans++;
            while(!list[vertex].isEmpty()){
                dfs(list[vertex].removeFirst());
            }
        }
    }
}
