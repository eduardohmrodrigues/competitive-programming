class Solution {
    fun customSortString(order: String, s: String): String {
        var mapo: MutableMap<Char, Int> = s.groupingBy{ it }.eachCount().toMutableMap()
        var output = ""
        println(mapo)
        for (c in order) {
            if(mapo.contains(c)) {
                for(i in 0..mapo[c]!!-1) {
                    output += c
                }
                mapo.remove(c)
            }
        }

        return output + mapo.flatMap{(char, count) -> List(count){char}}.joinToString(separator = "")
    }
}
