import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t, n, speed, expected, index = 1;

        t = scanner.nextInt();
        while(t-- > 0) {
            n = scanner.nextInt();
            expected = -1;
            while(n-- > 0) {
                speed = scanner.nextInt();
                expected = Integer.max(speed, expected);
            }

            System.out.println("Case " + index + ": " + expected);
            ++index;
        }
    }
}
