import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Map<Character, Double> price = new HashMap<Character, Double>();
        int n = scanner.nextInt(), k, v, m;
        double payment;
        String c, line;

        while (n-- > 0){
            price.clear();
            payment = 0.0d;
            k = scanner.nextInt();

            while (k-- > 0){
                c = scanner.next();
                v = scanner.nextInt();
                price.put(c.charAt(0), v/100.0d);
            }

            m = scanner.nextInt();
            scanner.nextLine();

            while (m-- > 0){
                line = scanner.nextLine();
                for(int i=0; i<line.length(); ++i){
                    if(price.containsKey(line.charAt(i))) payment += price.get(line.charAt(i));
                }
            }

            System.out.println(String.format("%.2f$", payment));
        }
    }
}
