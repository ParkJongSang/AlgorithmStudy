import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int N;
    static ArrayList<Schedule> schedules = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);
    static int max = 0;
    public static void main(String[] args) {

        //initialize start
        N = sc.nextInt();

        for(int i = 0; i < N; i++){
            int take = sc.nextInt();
            int earn = sc.nextInt();
            schedules.add(new Schedule(take, earn));
        }
        //initialize end

        //toSolve
        for(int i = 0; i < N; i++){
            dfs(schedules, i, 0);
        }
        System.out.println(max);

    }
    public static void dfs(ArrayList<Schedule> schedules, int date, int sum){
        if(date > N){
            //max = Math.max(sum, max);
            return;
        }else{
            max = Math.max(sum, max);
            for(int i = date; i < N; i++){
                if(schedules.get(i).take + i <= N){
                    dfs(schedules, schedules.get(i).take + i, sum + schedules.get(i).earn);
                }
            }
        }
    }
}

class Schedule{
    int take;
    int earn;

    Schedule(int take, int earn){
        this.take = take;
        this.earn = earn;
    }
}
