class Solution {
    fun hammingDistance(x: Int, y: Int): Int {
        val a = x and y
        val b = x or y
        val c = a xor b
        // println("a = ${a.toString(2)}  b = ${b.toString(2)}  c = ${c.toString(2)}")
        return c.toString(2).filter{it == '1'}.length
    }
}