/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

fun reverseArray(a: Array<Int>): Array<Int> {
    // Write your code here
    val b = Array(a.size) { i ->
        a[a.size-(i+1)]
    }
    return b
    // Kotlin native solution
    // a.reverse()
    // return a
}