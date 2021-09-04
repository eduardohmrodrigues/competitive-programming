import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a, b, line;
        double p1, p2;

        while (scanner.hasNextLine()) {
            a = scanner.nextLine();
            b = scanner.nextLine();

            line = getIntegerCode(a);
            p1 = decode(line);

            line = getIntegerCode(b);
            p2 = decode(line);

            if(p1 < p2) line = String.format("%.2f", 100*(p1/p2)) + " %";
            else line = String.format("%.2f", 100*(p2/p1)) + " %";
            System.out.println(line);
        }
    }

    public static int decode(String code) {
        int curr;
        while (code.length() > 1) {
            curr = 0;
            for(int i=0; i<code.length(); ++i) {
                curr += code.charAt(i) - 48;
            }

            code = "" + curr;
        }

        return Integer.parseInt(code);
    }

    public static String getIntegerCode(String name) {
        String line = "";
        for(int i=0; i<name.length(); ++i){
            if(isValidLower(name.charAt(i))){
                line = line.concat((name.charAt(i) - 96) + "");
            }else if(isValidUpper(name.charAt(i))){
                line = line.concat((name.charAt(i) - 64) + "");
            }
        }

        return line;
    }

    public static boolean isValidLower(int a) {
        // 97 - 122 a - z
        return (a > 96 && a < 123);
    }

    public static boolean isValidUpper(int a) {
        // 65 - 90  A - Z
        return (a > 64 && a < 91);
    }
}
