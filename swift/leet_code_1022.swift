/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func sumRootToLeaf(_ root: TreeNode?) -> Int {
        return order(root, 0)
    }
    
    func order(_ node: TreeNode?, _ current: Int) -> Int {
        guard let curNode = node else { return 0 }
        var current = current << 1
        current += curNode.val
        
        if isLeaf(node) {
            return current
        }
        
        return order(node?.right, current) + order(node?.left, current)
    }
    
    func isLeaf(_ node: TreeNode?) -> Bool {
        return node?.left == nil && node?.right == nil
    }
}
