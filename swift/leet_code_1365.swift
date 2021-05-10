func smallerNumbersThanCurrent(_ nums: [Int]) -> [Int] {
    var result = [Int]()
    
    for indexA in 0..<nums.count {
        var count = 0
        for indexB in indexA..<nums.count {
            if indexA != indexB, nums[indexA] > nums[indexB] {
                count = count + 1
            }
        }
        result.append(count)
    }
    
    return result
}
