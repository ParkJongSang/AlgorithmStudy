import java.util.Scanner;

/*
0과 1로된 사다리를 건너 가장 짧은 거리의 경로의 x좌표를 출력하는 것

쉽다.

완전탐색으로 봐도 무방할것 같다.

다만 현재 가지고 있는 최소값보다 검색하고있는 경로의 값이 커지는 순간 탐색을 종료하고 다음 경로로 넘어가는 것이

성능에 조금이나마 도움이 될것.
*/

public class Solution {
    private final static int ARR_LENGTH = 100;
    private static int tc;
    private static int[][] arr = new int[ARR_LENGTH][ARR_LENGTH];
    private static Scanner scanner = new Scanner(System.in);
    private static ArrayList arrayList = new ArrayList(ARR_LENGTH);
    private static int min;
    private static int count;
    private static int position;

    public static void main(String[] args) {

        for(int testCase = 1; testCase <= 10; testCase++){

            tc = scanner.nextInt();

            min = Integer.MAX_VALUE;
            position = 0;

            for(int i = 0; i < ARR_LENGTH; i++){
                for(int j = 0; j < ARR_LENGTH; j++){
                    arr[i][j] = scanner.nextInt();
                    if(i == 0 && arr[i][j] == 1){
                        arrayList.addLast(j);
                    }
                }
            }

            while(arrayList.getSize() > 0){
                int current_x = arrayList.remove(0);
                int x = current_x;
                int y = 0;

                count = 0;

                //System.out.print(x+" ");

                while(y < ARR_LENGTH){
                    //down
                    //
                    if(hasLeft(arr, y , x)){
                        while(hasLeft(arr, y, x)){
                            x--;
                            count++;
                        }
                    }else if(hasRight(arr, y, x)){
                        while(hasRight(arr, y, x)){
                            x++;
                            count++;
                        }
                    }

                    y++;

                }

                //System.out.println(count);

                if(min >=count){
                    min = count;
                    position = current_x;
                }
            }

            System.out.println("#"+tc+" "+position);

        }
    }

    public static boolean hasLeft(int[][] arr,int y , int x){
        if(x > 0 && arr[y][x-1] > 0){
            return true;
        }
        return false;
    }

    public static boolean hasRight(int[][] arr, int y, int x){
        if(x < arr.length - 1 && arr[y][x+1] > 0){
            return true;
        }
        return false;
    }
}

class ArrayList{
    int size;
    int[] arrList;

    public ArrayList(int size){
        this.size = 0;
        this.arrList = new int[size];
    }

    public void addFirst(int value){
        for(int i = size; i > 0; i++){
            arrList[i] = arrList[i-1];
        }
        arrList[0] = value;
        size++;
    }

    public void addLast(int value){
        if(size == 0){
            addFirst(value);
        }else{
            arrList[size] = value;
            size++;
        }
    }

    public void add(int idx, int value){
        if(idx == 0){
            addFirst(value);
        }else{
            for(int i = size; i > idx; i--){
                arrList[i+1] = arrList[i];
            }
            arrList[idx] = value;
            size++;
        }
    }

    public int remove(int idx){

        int toRemove = arrList[idx];

        for(int i = idx; i < size; i++){
            arrList[i] = arrList[i+1];
        }
        arrList[size-1] = 0;
        size--;

        return toRemove;
    }

    public int getSize(){
        return this.size;
    }
}