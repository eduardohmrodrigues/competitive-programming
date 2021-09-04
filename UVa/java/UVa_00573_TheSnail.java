import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int height, initialClimbDistance, nightSlide, fatiguePercentage, day;
        double currClimbDistance, currHeight, dailyDrop;
        boolean stop;
        height = scanner.nextInt();

        while(height > 0){
            stop = false;
            day = 1;
            currHeight = 0;
            initialClimbDistance = scanner.nextInt();
            nightSlide = scanner.nextInt();
            fatiguePercentage = scanner.nextInt();
            currClimbDistance = initialClimbDistance;
            dailyDrop = initialClimbDistance*(fatiguePercentage/100.0);

            while(!stop) {
                currHeight += currClimbDistance;

                if(currHeight > height) {
                    stop = true;
                }else{
                    currHeight -= nightSlide;
                    currClimbDistance -= dailyDrop;
                    currClimbDistance = currClimbDistance < 0 ? 0 : currClimbDistance;

                    if(currHeight < 0) {
                        stop = true;
                    }
                }

                if(currHeight <= height && currHeight >= 0){
                    ++day;
                }
            }

            if(currHeight < 0) System.out.println("failure on day " + day);
            else System.out.println("success on day " + day);

            height = scanner.nextInt();
        }
    }
}
