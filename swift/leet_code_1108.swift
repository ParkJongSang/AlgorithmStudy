class Solution {
    func defangIPaddr(_ address: String) -> String {
        let splitedAddress = address.split(separator: ".")
        return splitedAddress.joined(separator: "[.]")
    }
}
