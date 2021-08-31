import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tests, a, b;
        tests = scanner.nextInt();

        while(tests-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();

            if(a < b) System.out.println("<");
            else if (a > b) System.out.println(">");
            else System.out.println("=");
        }
    }
}
