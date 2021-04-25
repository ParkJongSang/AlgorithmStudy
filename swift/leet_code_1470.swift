func shuffle(_ nums: [Int], _ n: Int) -> [Int] {
    var xList = [Int]()
    var yList = [Int]()
    var result = [Int]()
    
    for index in 0..<nums.count {
        if index < n {
            xList.append(nums[index])
        } else {
            yList.append(nums[index])
        }
    }
    
    for index in 0..<n {
        result.append(xList[index])
        result.append(yList[index])
    }
    
    return result
}
