func numIdenticalPairs(_ nums: [Int]) -> Int {
    var result = 0
    
    for indexA in 0..<nums.count {
        for indexB in indexA..<nums.count {
            if indexA < indexB, nums[indexA] == nums[indexB] {
                result = result + 1
            }
        }
    }

    return result
}
