import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long n, curr;
        curr = scanner.nextLong();
        String line;
        while(curr != 0){
            line = String.valueOf(curr);
            while(line.length() > 1){
                n = 0;
                for(int i=0; i<line.length(); ++i){
                    n += Integer.parseInt(String.valueOf(line.charAt(i)));
                }
                line = String.valueOf(n);
            }

            System.out.println(line);
            curr = scanner.nextLong();
        }
    }
}
