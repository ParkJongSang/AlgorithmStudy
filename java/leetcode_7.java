class Solution {
    public int reverse(int x) {
        String s = x+"";
        StringBuffer sb = new StringBuffer();
        Boolean minusFlag = false;
        int ret;
        
        if(s.charAt(0) == '-') {
            minusFlag = true;
            s = s.substring(1);
        }
        sb.append(s);
        sb.reverse();
        try {
            ret = Integer.parseInt(sb.toString());
        } catch (Exception e) {
            ret = 0;
        }
        
        if(minusFlag == true) ret *= -1;
        
        return ret;
    }
}
