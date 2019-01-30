import java.util.Scanner;

public class Main {
    static int son_A, mother_A;
    static int son_B, mother_B;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        son_A = sc.nextInt(); mother_A = sc.nextInt();
        son_B = sc.nextInt(); mother_B = sc.nextInt();
        solve();
    }

    public static void solve(){
        //항상 A가 B보다 크도록
        if(mother_A < mother_B){
            int temp_mother = mother_A;
            mother_A = mother_B;
            mother_B = temp_mother;
            int temp_son = son_A;
            son_A = son_B;
            son_B = temp_son;
        }
        //분모 최소공배수
        int new_mother = lcm(mother_A, mother_B);

        //각 분자는 최소공배수 / 각 분모
        int new_son_A = son_A * (new_mother / mother_A);
        int new_son_B = son_B * (new_mother / mother_B);

        //결과값의 분자는 각 분자의 합.
        int new_son = new_son_B + new_son_A;

        //기약분수를 만들어줘야함
        int gcd_for_div = gcd(Math.max(new_son, new_mother), Math.min(new_son, new_mother));
        new_son /= gcd_for_div;
        new_mother /= gcd_for_div;

        System.out.println(new_son+" "+new_mother);
    }

    public static int lcm(int a, int b){
        return a*b/gcd(a,b);
    }

    public static int gcd(int a, int b){
        if(b==0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }
}
