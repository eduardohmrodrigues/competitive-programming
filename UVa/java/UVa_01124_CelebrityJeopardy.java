import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line;

        while(scanner.hasNextLine()) {
            line = scanner.nextLine();
            System.out.println(line);
        }
    }
}
