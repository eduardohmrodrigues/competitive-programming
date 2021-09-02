import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();

        String line;
        while(n-- > 0){
            line = scanner.nextLine();
            if (line.equals("1") || line.equals("4") || line.equals("78")) {
               System.out.println("+");
            } else if (line.endsWith("35")) {
                System.out.println("-");
            } else if (line.charAt(0) == '9' && line.endsWith("4")) {
                System.out.println("*");
            } else {
                System.out.println("?");
            }
        }
    }
}
