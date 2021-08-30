import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line;
        int index = 1;

        while(scanner.hasNextLine()) {
            line = scanner.nextLine();

            for(int i=0; i<line.length(); ++i) {
                if(line.charAt(i) == '"') {
                    if(index == 1) {
                        System.out.print("``");
                        index = 2;
                    }else{
                        System.out.print("''");
                        index = 1;
                    }
                }else{
                    System.out.print(line.charAt(i));
                }
            }
            System.out.println();
        }
    }
}
