import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n, f, s, a, e, cost;
        n = scanner.nextInt();

        while(n-- > 0) {
            cost = 0;
            f = scanner.nextInt();

            while(f-- > 0){
                s = scanner.nextInt();
                a = scanner.nextInt();
                e = scanner.nextInt();

                if(a != 0) cost += s*e;
            }

            System.out.println(cost);
        }
    }
}
