class NumArray(nums: IntArray) {

    private val _nums: IntArray = nums;

    fun update(index: Int, `val`: Int) {
        _nums[index] = `val`
    }

    fun sumRange(left: Int, right: Int): Int {
        return _nums.sliceArray(left..right).sum()
        
        // Initial solution
        // var sum = 0
        // for(i in left..right) sum += _nums[i]
        // return sum
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = NumArray(nums)
 * obj.update(index,`val`)
 * var param_2 = obj.sumRange(left,right)
 */
