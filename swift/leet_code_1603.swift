
class ParkingSystem {    
    private enum CarType: Int {
        case big = 1
        case medium = 2
        case small = 3
    }
    
    private let big: Int
    private let medium: Int
    private let small: Int
    
    private var currentBig: Int = 0
    private var currentMedium: Int = 0
    private var currentSmall: Int = 0
    
    init(_ big: Int, _ medium: Int, _ small: Int) {
        self.big = big
        self.medium = medium
        self.small = small
    }
    
    func addCar(_ carType: Int) -> Bool {
        guard let carSize = CarType.init(rawValue: carType) else { return false }
        
        if checkAvailable(carType: carSize) {
            enterPark(carType: carSize)
            return true
        } else {
            return false
        }
    }
    
    private func checkAvailable(carType: CarType) -> Bool {
        switch carType {
        case .big: return (big >= currentBig + 1)
        case .medium: return (medium >= currentMedium + 1)
        case .small: return (small >= currentSmall + 1)
        }
    }
    
    private func enterPark(carType: CarType) {
        switch carType {
        case .big: currentBig = currentBig + 1
        case .medium: currentMedium = currentMedium + 1
        case .small: currentSmall = currentSmall + 1
        }
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * let obj = ParkingSystem(big, medium, small)
 * let ret_1: Bool = obj.addCar(carType)
 */
