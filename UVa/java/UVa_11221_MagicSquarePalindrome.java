import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String sentence, aux, tmp;
        String[] words;
        boolean isMagic;
        int sqrtVal, curr = 1, t = scanner.nextInt();
        scanner.nextLine();
        while(t-- > 0) {
            isMagic = true;
            sentence = scanner.nextLine();

            sentence = sentence.replace(",", "");
            sentence = sentence.replace(".", "");
            sentence = sentence.replace("?", "");
            sentence = sentence.replace("!", "");
            sentence = sentence.replace("(", "");
            sentence = sentence.replace(")", "");
            sentence = sentence.replace(" ", "");

            // if palindrome, we know that all lines are equal (front to back, and back to front)
            isMagic &= isPalindrome(sentence);
            sqrtVal = ((int) Math.sqrt(sentence.length()));
            isMagic &= sqrtVal*sqrtVal == sentence.length();

            if(isMagic){
                words = new String[sqrtVal];
                for(int i=0; i<sqrtVal; ++i) words[i] = sentence.substring(sqrtVal*i, sqrtVal*i + sqrtVal);
            }else{
                words = new String[0];
            }

            for(int i=0; i<words.length && isMagic; ++i){
                aux = "";
                tmp = "";
                // Here we create the words that would be on the columns
                for(int j=0; j<words.length; ++j){
                    aux += words[j].charAt(i);
                    tmp += words[(words.length - 1) - i].charAt((words.length - 1) - j);
                }
                // And check if they match with the expected word
                isMagic &= aux.equals(words[i]) && tmp.equals(words[i]);
            }

            System.out.println("Case #" + curr + ":");
            if(isMagic) System.out.println(words.length);
            else  System.out.println("No magic :(");
            ++curr;
        }
    }

    public static boolean isPalindrome(String line) {
        boolean itIs = true;
        for(int i=0; i<line.length()/2 && itIs; ++i){
            itIs &= line.charAt(i) == line.charAt((line.length()-1)-i);
        }

        return itIs;
    }
}
