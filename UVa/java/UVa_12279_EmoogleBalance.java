import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, x, balance;
        int index = 1;
        n = scanner.nextInt();

        while (n != 0) {
            balance = 0;
            while(n-- > 0){
                x = scanner.nextInt();
                balance += (x > 0 ? 1 : -1);
            }
            System.out.println("Case " + index + ": " + balance);
            ++index;
            n = scanner.nextInt();
        }
    }
}
