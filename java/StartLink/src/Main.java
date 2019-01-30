import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    //첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다.
    //각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.
    static int N;
    static int S[][];
    static int team[];
    static Scanner sc = new Scanner(System.in);
    static int min = 9999999;

    public static void main(String[] args) {
        N = sc.nextInt();
        S = new int[N][N];
        team = new int[N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                S[i][j] = sc.nextInt();
            }
        }

        solve(0,0);

        System.out.println(min);
    }

    public static int calTeamAbilityDifference(){
        ArrayList<Integer> team_a = new ArrayList<>();
        ArrayList<Integer> team_b = new ArrayList<>();
        int team_a_power = -1;
        int team_b_power = -1;

        for(int i = 0; i < team.length; i++){
            if(team[i] == 1){
                team_a.add(i);
            }else{
                team_b.add(i);
            }
        }

        for(int i = 0; i < team_a.size(); i++){
            for(int j = i+1; j < team_a.size(); j++){
                team_a_power += S[team_a.get(i)][team_a.get(j)] + S[team_a.get(j)][team_a.get(i)];
                team_b_power += S[team_b.get(i)][team_b.get(j)] + S[team_b.get(j)][team_b.get(i)];
            }
        }

        return Math.abs(team_a_power - team_b_power);

    }

    public static void solve(int index, int list_size){
        if(index >= N){
            return;
        }
        if(list_size >= N / 2){
            min = Math.min(min, calTeamAbilityDifference());
            return;
        }
        team[index] = 1;
        solve(index+1, list_size+1);
        team[index] = 0;
        solve(index+1, list_size);
    }

}
