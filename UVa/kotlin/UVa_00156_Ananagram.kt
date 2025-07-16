import kotlin.text.*
import kotlin.collections.*
import kotlin.io.*
import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)

    var line = scanner.next()
    var anagramDict = mutableMapOf<String, MutableList<String>>()
    var keyCharArray: CharArray
    var key: String
    while (line != "#") {
        keyCharArray = line.lowercase().toCharArray()
        keyCharArray.sort()
        key = keyCharArray.joinToString("")

        if (!anagramDict.contains(key)) {
            anagramDict[key] = mutableListOf<String>()
        }
        anagramDict[key]!!.add(line)
        line = scanner.next()
    }

    var ananagramList = mutableListOf<String>()
    for (element in anagramDict.values) {
       if (element.size == 1) {
           ananagramList.add(element[0])
       }
    }
    ananagramList.sort()
    for (element in ananagramList) {
        println(element)
    }
}