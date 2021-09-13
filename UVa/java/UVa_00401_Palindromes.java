import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Map<Character, Character> mirror = new HashMap<Character, Character>(21);
        mirror.put('A', 'A'); mirror.put('E', '3'); mirror.put('H', 'H');
        mirror.put('I', 'I'); mirror.put('J', 'L'); mirror.put('L', 'J');
        mirror.put('M', 'M'); mirror.put('O', 'O'); mirror.put('S', '2');
        mirror.put('T', 'T'); mirror.put('U', 'U'); mirror.put('V', 'V');
        mirror.put('W', 'W'); mirror.put('X', 'X'); mirror.put('Y', 'Y');
        mirror.put('Z', '5'); mirror.put('1', '1'); mirror.put('2', 'S');
        mirror.put('3', 'E'); mirror.put('5', 'Z'); mirror.put('8', '8');

        Scanner scanner = new Scanner(System.in);
        String line;
        boolean isPalindrome, isMirrored;

        do{

            line = scanner.nextLine();
            isPalindrome = isPalindrome(line);
            isMirrored = isMirrored(line, mirror);

            if(!isPalindrome && !isMirrored){
                System.out.println(line + " -- is not a palindrome.");
            }else if(isPalindrome && isMirrored){
                System.out.println(line + " -- is a mirrored palindrome.");
            }else if(isPalindrome){
                System.out.println(line + " -- is a regular palindrome.");
            }else if(isMirrored){
                System.out.println(line + " -- is a mirrored string.");
            }

            System.out.println();
        }while(scanner.hasNextLine());

    }

    public static boolean isPalindrome(String line) {
        boolean itIs = true;
        for(int i=0; i<line.length()/2 && itIs; ++i){
            itIs &= line.charAt(i) == line.charAt((line.length()-1)-i);
        }

        return itIs;
    }

    public static boolean isMirrored(String line, Map<Character, Character> mirror) {
        boolean itIs = true;
        char a, b;
        int limit = line.length()%2 == 1 ? ((line.length()/2)+1) : line.length()/2;
        for (int i=0; i<limit && itIs; ++i) {
            a = line.charAt(i);
            b = line.charAt((line.length()-1)-i);

            itIs = mirror.containsKey(a) && mirror.get(a) == b;
        }

        return itIs;
    }
}
