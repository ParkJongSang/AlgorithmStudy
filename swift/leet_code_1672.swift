func maximumWealth(_ accounts: [[Int]]) -> Int {
    var maxValue = 0
    
    for numbers in accounts {
        let result = numbers.reduce(0, { $0 + $1 })
        maxValue = max(result, maxValue)
    }
    
    return maxValue
}
