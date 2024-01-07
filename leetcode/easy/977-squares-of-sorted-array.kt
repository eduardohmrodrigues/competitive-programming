class Solution {
    fun sortedSquares(nums: IntArray): IntArray {
        var pivotL = -1
        var pivotR = -1
        
        // find the positive and lock pivotR
        for(i in 0..nums.size-1) {
            if(nums[i] >= 0) {
                pivotR = i
                pivotL = pivotR - 1
                break
            }
        }
        
        // full negative array
        if(pivotR == -1) {
            pivotL = nums.size-1
            pivotR = nums.size
        }
        
        // we always have the left element
        var offLeft = pivotL == -1
        var offRight = pivotR == nums.size
        var sqrNum: MutableList<Int> = ArrayList()
        while(!offLeft || !offRight) {
            if(!offLeft && !offRight) {
                val left = nums[pivotL]
                val right = nums[pivotR]
                if (Math.abs(left) < Math.abs(right)) {
                    sqrNum.add(left*left)
                    --pivotL
                } else {
                    sqrNum.add(right*right)
                    ++pivotR
                }
            } else if(!offLeft) {
                val left = nums[pivotL]
                sqrNum.add(left*left)
                --pivotL
            } else {
                val right = nums[pivotR]
                sqrNum.add(right*right)
                ++pivotR
            }
            
            offLeft = pivotL == -1
            offRight = pivotR == nums.size
        }
        
        return sqrNum.toIntArray()
    }
}
