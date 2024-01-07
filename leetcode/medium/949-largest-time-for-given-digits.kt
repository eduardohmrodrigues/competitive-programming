class Solution {
    fun largestTimeFromDigits(arr: IntArray): String {
        var latest = ""
        for(i in 0..arr.size-1) {
            val h1 = arr[i]
            if(h1 > 2) continue
            for(j in 0..arr.size-1) {
                if(i == j) continue
                val hour = h1*10+arr[j]
                if(hour > 23) continue
                for (x in 0..arr.size-1) {
                    if (i == x || j == x) continue
                    val m1 = arr[x]
                    if(m1 > 5) continue
                    for (y in 0..arr.size-1) {
                        if(i == y || j == y || x == y) {
                            continue
                        }
                        val min = m1*10+arr[y]
                        if(min < 60) {
                            val complete = "$h1${arr[j]}:$m1${arr[y]}"
                            if (complete > latest) latest = complete
                        }
                    }
                }
            }
        }
        
        return latest
    }
}
