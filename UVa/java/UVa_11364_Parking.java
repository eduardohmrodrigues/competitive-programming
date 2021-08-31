import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int tests, min, max, n, aux;

        tests = scanner.nextInt();
        while(tests-- > 0) {
            min = 100;
            max = -1;
            n = scanner.nextInt();

            while(n-- > 0){
                aux = scanner.nextInt();
                min = min > aux ? aux : min;
                max = max < aux ? aux : max;
            }

            System.out.println((max - min)*2);
        }
    }
}
