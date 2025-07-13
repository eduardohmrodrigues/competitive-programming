/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

fun calculateHourglassForCoord(i: Int, j: Int, arr: Array<Array<Int>>): Int {
    return arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                        arr[i+1][j+1] +
            arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]
}

fun hourglassSum(arr: Array<Array<Int>>): Int {
    var maxSum = calculateHourglassForCoord(0, 0, arr)
    var temp = 0
    // Write your code here
    for (i in 0..<arr.size-2) {
        for (j in 0..<arr[i].size-2) {
            temp = calculateHourglassForCoord(i, j, arr)
            maxSum = if (maxSum > temp) maxSum else temp
        }
    }

    return maxSum
}