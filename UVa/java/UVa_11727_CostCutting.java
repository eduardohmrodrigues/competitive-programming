import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t, a, b, c;
        int index = 1;
        t = scanner.nextInt();
        while(t-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();

            if(isBetween(a, b, c)) {
                System.out.println("Case " + index + ": " + a);
            }else if(isBetween(b, a, c)){
                System.out.println("Case " + index + ": " + b);
            }else{
                System.out.println("Case " + index + ": " + c);
            }
            ++index;
        }
    }

    public static boolean isBetween(int a, int b, int c) {
        return (a < c && a > b) || (a < b && a > c);
    }
}
