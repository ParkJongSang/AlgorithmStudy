
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;


/*
입력의 범위가 클경우 int형이 아닌 long형을 사용할 것
int의 경우 실패가 뜰 확률이 있음
 */
public class Main {
    static long number_of_room;
    static LinkedList<Long> number_of_students;
    static long main_superviser_can_see;
    static long vice_superviser_can_see;
    static long ans = 0;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        //initialize
        number_of_room = sc.nextLong();
        number_of_students = new LinkedList<>();
        for(int i = 0; i < number_of_room; i++){
            number_of_students.add(sc.nextLong());
        }

        main_superviser_can_see = sc.nextLong();
        vice_superviser_can_see = sc.nextLong();

        //toSolve
        Collections.sort(number_of_students);

        solve(number_of_students, main_superviser_can_see, vice_superviser_can_see);

        System.out.println(ans);
    }

    public static void solve(LinkedList<Long> arrayList, long main_superviser_can_see, long vice_superviser_can_see){
        boolean is_first = true;
        boolean not_exist_supervisor = true;
        long number_of_main_supervisor = 0;
        long number_of_vice_supervisor = 0;
        long can_see = 0;
        while(!arrayList.isEmpty()){
            long this_rooms_number_of_students = arrayList.removeFirst();
            //가장 학생이 작은 방을 방문할때
            if(is_first){
                //현재 볼수있는 인원이 방의 인원보다 작으면 반복문 진입
                while(can_see < this_rooms_number_of_students){
                    //총 감독관이 없다면 한명 세운다.
                    if(not_exist_supervisor){
                        //총 감독관은 1명을 넘을 수 없으므로 1명만 세움
                        number_of_main_supervisor = 1;
                        can_see = can_see + main_superviser_can_see;
                        not_exist_supervisor = false;
                    }else{
                        //총 감독관이 있다면 부 감독관을 늘린다.
                        number_of_vice_supervisor++;
                        can_see = can_see + vice_superviser_can_see;
                    }
                }
                ans = ans + number_of_main_supervisor;
                ans = ans + number_of_vice_supervisor;
                is_first = false;
            }else{
                while(can_see < this_rooms_number_of_students){
                    //이미 총 감독관이 있는 상태이므로 부감독관만 늘린다.
                    number_of_vice_supervisor++;
                    can_see += vice_superviser_can_see;
                }
                //한방에 총 감독관은 무조건 한명이 있는 상태이므로 항상 매 방추가해준다.
                ans = ans + number_of_main_supervisor;
                ans = ans + number_of_vice_supervisor;
            }
        }
    }
}
