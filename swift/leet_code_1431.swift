func kidsWithCandies(_ candies: [Int], _ extraCandies: Int) -> [Bool] {
    guard let maxValue = candies.max() else { return [false] }
    
    var result = [Bool]()
    for candyCount in candies {
        let trueOrFalse = (candyCount + extraCandies >= maxValue)
        result.append(trueOrFalse)
    }
    
    return result
}
