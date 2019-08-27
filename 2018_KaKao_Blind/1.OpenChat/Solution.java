import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        HashMap<String, String> map = new HashMap<>();
        ArrayList<String> vector = new ArrayList<>();
        String[] answer;
        int answer_size = 0;
        int record_len = record.length;
        for(int i = 0; i < record_len; i++){
            String input[] = record[i].split(" ");
            if(input[0].equals("Enter")){
                answer_size++;
                vector.add(input[1]);
                map.put(input[1], input[2]);
            }else if(input[0].equals("Change")){
                map.put(input[1], input[2]);
            }else{
                answer_size++;
            }
        }
        answer = new String[answer_size];
        answer_size = 0;
        for(int i = 0; i < record_len; i++){
            String input[] = record[i].split(" ");
            if(input[0].equals("Enter")){
                answer[answer_size++] = map.get(input[1])+"님이 들어왔습니다.";
            }else if(input[0].equals("Leave")){
                answer[answer_size++] = map.get(input[1])+"님이 나갔습니다.";
            }   
        }
        return answer;
    }
}