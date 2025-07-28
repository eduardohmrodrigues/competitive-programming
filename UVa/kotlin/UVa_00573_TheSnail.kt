import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    
    var goal: Int = scanner.nextInt()
    var climbDistance: Int = 0
    var nightDrop: Int = 0
    var dropFactor: Int = 0
    var factoredDrop: Double = 0.0
    var currentHeight: Double = 0.0
    var day = 0
    var currentClimbDistance: Double = 0.0

    while(scanner.hasNext() && goal != 0) {
        climbDistance = scanner.nextInt()
        nightDrop = scanner.nextInt()
        dropFactor = scanner.nextInt()
        
        factoredDrop = climbDistance.toDouble() * (dropFactor.toDouble()/100.0)
        day = 0
        currentHeight = 0.0

        while(currentHeight <= goal && currentHeight >= 0) {
            currentClimbDistance = climbDistance - day*factoredDrop
            if (currentClimbDistance > 0) {
                currentHeight += currentClimbDistance
            }
            day += 1
            if (currentHeight <= goal) {
                currentHeight -= nightDrop
            }
        }

        if (currentHeight < 0) {
            println("failure on day $day")
        } else {
            println("success on day $day")
        }
        goal = scanner.nextInt()
    }
    
}
