
import java.util.*;

public class Main {

    private static int test_case;
    private static int num_of_rest;
    private static ArrayList<Point> result_list = new ArrayList<>();

    //스카이라인 저장할 우선순위 큐
    private static PriorityQueue<Point> points = new PriorityQueue<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        test_case = scanner.nextInt();

        for(int i = 1; i <= test_case; i++){
            result_list.clear();
            points.clear();
            num_of_rest = scanner.nextInt();
            for(int j = 0; j < num_of_rest; j++){
                Point temp = new Point();
                temp.x = scanner.nextInt();
                temp.y = scanner.nextInt();
                temp.index = j;
                points.add(temp);
            }

            skyline(result_list, points);

            System.out.print("#"+i);
            for(int j = 0; j < result_list.size(); j++){

                System.out.print(" "+(result_list.get(j).index+1));
            }
            System.out.println();

        }
    }

    public static void skyline(ArrayList<Point> result_list, PriorityQueue<Point> points){

        result_list.add(points.poll());

        while(!points.isEmpty()){
            Point temp = points.poll();
            if(result_list.get(result_list.size()-1).x == temp.x && result_list.get(result_list.size()-1).y > temp.y){
                //result_list.remove(result_list.size()-1);
                result_list.add(temp);
            }else if(result_list.get(result_list.size()-1).x < temp.x){
                boolean exist = false;
                boolean delete = false;
                int index = 0;
                for(int i = 0; i < result_list.size(); i++){
                    if(result_list.get(i).y <= temp.y){
                        exist = true;
                    }
                }
                if (exist) {
                    exist = false;
                }else{
                    result_list.add(temp);
                }
            }else if(result_list.get(result_list.size()-1).x < temp.x && result_list.get(result_list.size()-1).y > temp.y){
                continue;
            }else{
                continue;
            }
        }
    }
}

class Point implements Comparable<Point>{
    int x;
    int y;
    int index;

    @Override
    public int compareTo(Point o) {
        if(this.x == o.x){
            //x좌표가 같을경우 y기준으로 정렬
            return this.y - o.y;
        }else{
            //x좌표 기준으로 정렬
            return this.x - o.x;
        }
    }
}


