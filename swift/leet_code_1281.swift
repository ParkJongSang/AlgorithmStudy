func subtractProductAndSum(_ n: Int) -> Int {
    let digits = numberToDigits(n)
    let product = digits.reduce(1, { $0 * $1 })
    let sum = digits.reduce(0, { $0 + $1 })
    
    return product - sum
}

private func numberToDigits(_ n: Int) -> [Int] {
    var digits = [Int]()
    var num = n
    digits.append(num%10)
    
    while num >= 10 {
        num = num / 10
        digits.append(n%10)
    }
    
    return digits.reversed()
}
