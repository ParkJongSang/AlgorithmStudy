class Solution {
    func defangIPaddr(_ address: String) -> String {
        var splitedAddress = address.split(separator: ".")
        return splitedAddress.joined(separator: "[.]")
    }
}
