class Solution {
    func numberOfSteps (_ num: Int) -> Int {
        var step = 0
        var dupNum = num
        while dupNum > 0 {
            if dupNum % 2 == 0 {
                dupNum /= 2
            } else {
                dupNum -= 1
            }
            step += 1
        }
        return step
    }
}
