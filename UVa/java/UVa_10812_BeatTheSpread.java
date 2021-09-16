import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long s, d, x, y, t = scanner.nextLong();

        while(t-- > 0){
            s  = scanner.nextLong();
            d  = scanner.nextLong();

            x = ((s + d) / 2);
            y = s - x;

            if(x < 0 || y < 0 || x*2 != (s+d)) {
                System.out.println("impossible");
            }else{
                System.out.println(x + " " + y);
            }
        }

    }
}
