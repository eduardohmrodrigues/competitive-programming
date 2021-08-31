import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long t, n;
        String txt;
        t = scanner.nextInt();
        while(t-- > 0) {
            n = scanner.nextInt();
            txt = Long.toString((((n*567/9)+7492)*235/47)-498);
            txt = txt.length() < 2 ? "0".concat(txt) : txt;
            System.out.println(txt.charAt(txt.length()-2));
        }
    }
}
