class Solution {
    fun canWinNim(n: Int): Boolean {
        var myTurn = false
        var stones = n
        
        if(n < 4) return true
        for(i in 3 downTo 1) {
            if((n-i)%4 == 0) {
                return true
            }
        }
        
        return false
    }
}