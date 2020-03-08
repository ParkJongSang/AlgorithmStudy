class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int len = s.length();
        Set<Character> set = new HashSet<>();
        
        while(left < len && right < len) {
            if( set.contains(s.charAt(right)) == false ) {
                set.add(s.charAt(right++));
                ans = Math.max(ans, right - left);
            } else {
                set.remove(s.charAt(left++));
            }
        }
        
        return ans;
        
    }
}
