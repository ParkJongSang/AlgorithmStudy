func numJewelsInStones(_ jewels: String, _ stones: String) -> Int {
    var result = 0
    
    for stoneChar in stones {
        for jewelsChar in jewels {
            if stoneChar == jewelsChar {
                result = result + 1
            }
        }
    }
    
    return result
}
