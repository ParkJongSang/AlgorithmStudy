import java.util.*;

class Solution {
    class Food{
        int time;
        int idx;
        
        Food(int t, int i){
            time = t;
            idx = i;
        }
    };
    
    Comparator<Food> CompTime = new Comparator<Food>(){
        public int compare(Food a, Food b){
            return a.time - b.time;
        }
    };
    Comparator<Food> CompIdx = new Comparator<Food>(){
        public int compare(Food a, Food b){
            return a.idx - b.idx;
        }
    };
    public int solution(int[] food_times, long k) {
        List<Food> foods = new LinkedList<Food>();
        int n = food_times.length;
        for(int i = 0; i < n; i++){
            foods.add(new Food(food_times[i], i+1));
        }
        
        foods.sort(CompTime);
        
        int preTime = 0;
        int idx = 0;
        
        for(Food f : foods){
            long diff = f.time - preTime;
            if(diff != 0){
                long spend = diff * n;
                if(spend <= k){
                    k -= spend;
                    preTime = f.time;
                } else {
                    k %= n;
                    foods.subList(idx, food_times.length).sort(CompIdx);
                    return foods.get(idx+(int)k).idx;
                }
            }
            idx++;
            n--;
        }
        return -1;
    }
}