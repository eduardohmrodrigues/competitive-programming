/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

fun rotateLeft(d: Int, arr: Array<Int>): Array<Int> {
    // Write your code here
    var otpArr = Array<Int>(arr.size) { i ->
        arr[(i+d)%arr.size]
    }

    return otpArr
}