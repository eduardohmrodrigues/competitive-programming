import kotlin.io.*
import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)

    var tests = scanner.nextInt()
    var a: Int
    var b: Int
    while(tests-- > 0) {
        a = scanner.nextInt()
        b = scanner.nextInt()

        if (a > b) println(">")
        else if (b > a) println("<")
        else println("=")
    }
}