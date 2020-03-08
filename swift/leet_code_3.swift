class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var left = 0
        var right = 0
        var strLength = s.length
        var charSet = Set<Character>()
        var ret = 0
        
        while left < strLength && right < strLength {
            let currentChar = s[s.index(s.startIndex, offsetBy: right)]
            //print("\(strLength):\(left)-\(right) currentChar:\(currentChar)")
            if charSet.contains(currentChar) == false {
                charSet.insert(currentChar)
                right += 1
                if ret < right - left {
                    ret = right - left
                }
            } else {
                let toRemoveChar = s[s.index(s.startIndex, offsetBy: left)]
                left += 1
                charSet.remove(toRemoveChar)
            }
        }
        
        return ret
    }
}
