class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var map: Dictionary<Int, Int> = Dictionary<Int, Int>()
        var toRet = [Int]()
        for (index, value) in nums.enumerated() {
            map.updateValue(index, forKey: value)
        }
        
        for (index, value) in nums.enumerated() {
            let remain = target - value
            if map[remain] != nil, map[remain] != index {
                toRet.append(index)
                toRet.append(map[remain]!)
                break
            } 
        }
        
        return toRet
    }
}
