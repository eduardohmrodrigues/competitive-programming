import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k, n, m, x, y;

        k = scanner.nextInt();
        while(k != 0) {
            n = scanner.nextInt();
            m = scanner.nextInt();

            while(k-- > 0) {
                x = scanner.nextInt();
                y = scanner.nextInt();

                if(x == n || y == m) {
                    System.out.println("divisa");
                }else if(x > n){
                    System.out.println(y > m ? "NE" : "SE");
                }else{
                    System.out.println(y > m ? "NO" : "SO");
                }
            }

            k = scanner.nextInt();
        }
    }
}
