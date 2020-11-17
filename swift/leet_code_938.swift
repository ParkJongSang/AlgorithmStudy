/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func rangeSumBST(_ root: TreeNode?, _ low: Int, _ high: Int) -> Int {
        var leftSum = 0
        var rightSum = 0
        var current = 0
        
        if let currentVal = root?.val, currentVal >= low, currentVal <= high {
            current = currentVal
        }
    
        if let leftNode = root?.left {
            leftSum = rangeSumBST(leftNode, low, high)
        } 
        if let rightNode = root?.right {
            rightSum = rangeSumBST(rightNode, low, high)
        }
        
        return current + leftSum + rightSum
    }
}
