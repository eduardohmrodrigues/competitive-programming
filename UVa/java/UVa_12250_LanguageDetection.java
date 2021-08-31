import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Map<String, String> languages = new HashMap<String, String>(){
            {put("HELLO", "ENGLISH");}
            {put("HOLA", "SPANISH");}
            {put("HALLO", "GERMAN");}
            {put("BONJOUR", "FRENCH");}
            {put("CIAO", "ITALIAN");}
            {put("ZDRAVSTVUJTE", "RUSSIAN");}
        };

        int index = 1;
        String line = scanner.nextLine();

        while(!line.equals("#")) {
            if(languages.containsKey(line)) {
                System.out.println("Case " + index + ": " + languages.get(line));
            }else{
                System.out.println("Case " + index + ": UNKNOWN");
            }

            ++index;
            line = scanner.nextLine();
        }
    }
}
