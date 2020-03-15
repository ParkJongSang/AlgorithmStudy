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
    func mergeTrees(_ t1: TreeNode?, _ t2: TreeNode?) -> TreeNode? {
        var ret: TreeNode?
        if t1 == nil {
            ret = t2
            return ret
        }
        if t2 == nil {
            ret = t1
            return ret
        }
        guard let leftVal = t1?.val else {
            return nil
        }
        guard let rightVal = t2?.val else {
            return nil
        }
        ret = TreeNode(leftVal + rightVal)
        ret?.left = mergeTrees(t1?.left, t2?.left)
        //ret = TreeNode(leftVal + rightVal)
        ret?.right = mergeTrees(t1?.right, t2?.right)
        //ret = TreeNode(leftVal + rightVal)
        
        return ret
    }
}
