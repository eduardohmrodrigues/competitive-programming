/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun sumOfLeftLeaves(root: TreeNode?): Int {
        return findLeftLeaves(root, false)
    }
    
    fun findLeftLeaves(root: TreeNode?, isLeftNode: Boolean): Int {
        if(root == null) return 0
        
        if(root.left == null && root.right == null) {
            if(isLeftNode) return root.`val`
            else return 0
        }
        
        val lefto = findLeftLeaves(root.left, true)
        val righto = findLeftLeaves(root.right, false)
        
        return lefto + righto
    }
}
