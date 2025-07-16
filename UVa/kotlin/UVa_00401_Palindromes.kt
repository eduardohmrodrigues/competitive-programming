import kotlin.collections.*
import kotlin.io.*
import java.util.Scanner

val reverseMap = mapOf(
    'A' to 'A', 'E' to '3', 'H' to 'H', 'I' to 'I',
    'J' to 'L', 'L' to 'J', 'M' to 'M', 'O' to 'O',
    'S' to '2', 'T' to 'T', 'U' to 'U', 'V' to 'V',
    'W' to 'W', 'X' to 'X', 'Y' to 'Y', 'Z' to '5',
    '1' to '1', '2' to 'S', '3' to 'E', '5' to 'Z',
    '8' to '8'
)

fun main() {
    val scanner = Scanner(System.`in`)
    var isPalindrome = true
    var isMirrored = true

    while (scanner.hasNext()) {
        var line = scanner.nextLine()

        for (i in 0..<line.length) {
            isPalindrome = isPalindrome && line[i] == line[line.length - i - 1]
            isMirrored = isMirrored && line[line.length - i - 1] == reverseMap.get(line[i])

            if (!isPalindrome && !isMirrored) break
        }

        if (isPalindrome && isMirrored) {
            println("$line -- is a mirrored palindrome.")
        } else if (isMirrored) {
            println("$line -- is a mirrored string.")
        } else if (isPalindrome) {
            println("$line -- is a regular palindrome.")
        } else {
            println("$line -- is not a palindrome.")
        }
        println()
        isPalindrome = true
        isMirrored = true
    }
}
