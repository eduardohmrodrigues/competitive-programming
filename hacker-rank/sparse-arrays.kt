/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY stringList
 *  2. STRING_ARRAY queries
 */

fun matchingStrings(stringList: Array<String>, queries: Array<String>): Array<Int> {
    // Write your code here
    val occurCounter = mutableMapOf<String, Int>()

    stringList.forEach {
        if (!occurCounter.contains(it)) {
            occurCounter[it] = 0
        }
        occurCounter[it] = occurCounter[it]!! + 1
    }
    

    return queries.map { element ->
        occurCounter[element] ?: 0
    }.toTypedArray()
}