import java.util.Scanner
import kotlin.collections.ArrayDeque

fun main() {
    val scanner = Scanner(System.`in`)
    val q = scanner.nextInt()
    var op: Int
    var x: Int

    val myQueue = ArrayDeque<Int>()
    for (i in 0..<q) {
        op = scanner.nextInt()

        when (op) {
            1 -> {
                x = scanner.nextInt()
                myQueue.add(x)
            }
            2 -> myQueue.removeFirstOrNull()
            else -> println(myQueue.first())
        }
    }
}