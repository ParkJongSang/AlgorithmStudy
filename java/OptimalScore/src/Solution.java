import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * 성수가 들을수 있는 강좌의 수준과 성수의 수준을 최대로 올릴수 있는 강좌듣는 순서
 *
 * 최대값부터 차근차근히 들어보면 된다.
 *
 * 수식을 세우면 더욱더 쉽게 구현할 수 있다.
 */

public class Solution {

    private static int testCase;
    private static int totalLecture;
    private static int learnLecture;
    private static LinkedList<Integer> lectureList = new LinkedList<>();
    private static Scanner scanner = new Scanner(System.in);
    private static double result;

    public static void main(String[] args) {
        testCase = scanner.nextInt();

        for(int i = 1; i <= testCase; i++){

            result = (double)0;
            lectureList.clear();
            totalLecture = scanner.nextInt();
            learnLecture = scanner.nextInt();

            for(int j = 0; j < totalLecture; j++){
                int input = scanner.nextInt();
                lectureList.add(input);
            }

            Collections.sort(lectureList);
            Collections.reverse(lectureList);

            for(int j = 0; j < learnLecture; j++){
                result += (double)lectureList.removeFirst() * (double) Math.pow(2, learnLecture - j - 1);
            }

            result = result / Math.pow(2, learnLecture);

            System.out.print("#"+i+" ");
            System.out.format("%.6f\n", result);
        }
    }
}

