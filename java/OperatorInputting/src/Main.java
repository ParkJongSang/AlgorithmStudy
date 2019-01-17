import java.util.Scanner;

public class Main {
    //N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다.
    //또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
    //예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 예를 들어, 아래와 같은 식을 만들 수 있다.
    //
    //1+2+3-4×5÷6
    //1÷2+3+4-5×6
    //1+2÷3×4-5+6
    //1÷2×3-4+5+6
    //식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.
    //
    //1+2+3-4×5÷6 = 1
    //1÷2+3+4-5×6 = 12
    //1+2÷3×4-5+6 = 5
    //1÷2×3-4+5+6 = 7
    //N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

    //첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데,
    //차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.
    static int N;
    static long numbers[];
    static int operators[] = {0,0,0,0}; //0 : +, 1 : -, 2 : x, 3 : /
    static Scanner sc = new Scanner(System.in);
    static long min = Long.MAX_VALUE;
    static long max = Long.MIN_VALUE;
    public static void main(String[] args) {

        N = sc.nextInt();
        numbers = new long[N];
        for(int i = 0; i < N; i++){
            numbers[i] = sc.nextInt();
        }
        for(int i = 0; i < 4; i++){
            operators[i] = sc.nextInt();
        }

        solve(numbers, operators, 0, numbers[0]);

        System.out.println(max);
        System.out.println(min);
    }

    public static void solve(long numbers[], int operators[], int depth, long number){
        if(depth > N-2){
            if(min > number){
                min = number;
            }
            if(max < number){
                max = number;
            }
            return;
        }else{
            if(operators[0] > 0){
                operators[0] = operators[0] - 1;
                solve(numbers, operators, depth+1, number + numbers[depth+1]);
                operators[0] = operators[0] + 1;
            }
            if(operators[1] > 0){
                operators[1] = operators[1] - 1;
                solve(numbers, operators, depth+1, number - numbers[depth+1]);
                operators[1] = operators[1] + 1;
            }
            if(operators[2] > 0){
                operators[2] = operators[2] - 1;
                solve(numbers, operators, depth+1, number * numbers[depth+1]);
                operators[2] = operators[2] + 1;
            }
            if(operators[3] > 0){
                operators[3] = operators[3] - 1;
                solve(numbers, operators, depth+1, number / numbers[depth+1]);
                operators[3] = operators[3] + 1;
            }

        }
    }

}
