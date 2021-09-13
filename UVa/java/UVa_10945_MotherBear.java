package com.competitive.uva.palindrome;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String sentence = scanner.nextLine();
        boolean isPalindrome;
        while(!sentence.equals("DONE")) {

            sentence = sentence.toLowerCase();
            sentence = sentence.replace(".", "");
            sentence = sentence.replace(",", "");
            sentence = sentence.replace("!", "");
            sentence = sentence.replace("?", "");
            sentence = sentence.replace(" ", "");
            isPalindrome = isPalindrome(sentence);

            if(isPalindrome) System.out.println("You won't be eaten!");
            else  System.out.println("Uh oh..");
            sentence = scanner.nextLine();
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
