/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

fun dynamicArray(n: Int, queries: Array<Array<Int>>): Array<Int> {
    // Write your code here
    var arr = MutableList<MutableList<Int>>(n) {
        mutableListOf<Int>()
    }
    var answersArr = mutableListOf<Int>()
    var lastAnswer = 0
    var op: Int
    var x: Int
    var y: Int
    var idx: Int
    for (i in 0..<queries.size) {
        op = queries[i][0]
        x = queries[i][1]
        y = queries[i][2]

        idx = (x xor lastAnswer)%n
        if (op == 1) {
            arr[idx].add(y)
        } else {
            lastAnswer = arr[idx][y%arr[idx].size]
            answersArr.add(lastAnswer)
        }
    }
    return answersArr.toTypedArray()
}