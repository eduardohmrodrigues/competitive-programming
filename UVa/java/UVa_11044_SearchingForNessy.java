import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        int n, m;

        while (testCases > 0) {
            n = scanner.nextInt()/3;
            m = scanner.nextInt()/3;

            System.out.println(n*m);
            --testCases;
        }
    }
}
