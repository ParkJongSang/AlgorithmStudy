import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        int[] son = new int[N+2];
        int[] mother = new int[N+2];
        ArrayList<stage> al = new ArrayList<>();
        
        for(int i = 0; i < stages.length; i++){
            son[stages[i]]++;
        }
        
        mother[N+1] = son[N+1];
        for(int i = N; i > 0; i--){
            mother[i] = son[i] + mother[i+1];
        }
        
        for(int i = 1; i < N+1; i++){
            if(mother[i] == 0) {
                al.add(new stage(i, 0));
            }else{
                double tmp = (double)son[i]/(double)mother[i];
                al.add(new stage(i, tmp));
            }
        }
    
        Collections.sort(al, new myComparator());
        
        for(int i = 0; i < al.size(); i++){
            answer[i] = al.get(i).first;
            //System.out.println(al.get(i).first+" "+al.get(i).second);
        }
        return answer;
    }
    
    class myComparator implements Comparator<stage>{
        public int compare(stage s1, stage s2){
            if(s1.second == s2.second){
                return s1.first-s2.first;
            }else if(s1.second > s2.second){
                return -1;
            }else if(s1.second < s2.second){
                return 1;
            }else{
                return 0;
            }
        }
    }
    
    class stage{
        int first;
        double second;
        
        public stage(int first, double second){
            this.first = first;
            this.second = second;
        }
    }
}