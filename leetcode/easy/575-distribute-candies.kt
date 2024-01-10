class Solution {
    fun distributeCandies(candyType: IntArray): Int {
        var aliceCapacity = candyType.size/2
        var collectionDiversity = candyType.toSet().size
        
        if(collectionDiversity <= aliceCapacity) return collectionDiversity
        else return aliceCapacity
    }
}
