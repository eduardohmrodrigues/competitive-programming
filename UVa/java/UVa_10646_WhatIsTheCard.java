import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, y, currIteration, currCard, currCase = 1, tests = scanner.nextInt();
        scanner.nextLine();
        String line;
        String[] cards;
        char cardFace;

        while(tests-- > 0) {
            line = scanner.nextLine();
            cards = line.split("\\s+");

            y = 0;
            currIteration = 1;
            currCard = 26;
            while(currIteration < 4 && currCard >= 0){
                cardFace = cards[currCard].charAt(0);

                // not a number
                if(cardFace > 57) {
                    x = 10;
                }else{
                    x = cardFace - '0';
                }

                y += x;
                currCard -= (11 - x);
                ++currIteration;
            }

            if(currCard+1 >= y){
                System.out.println("Case " + currCase + ": " + cards[y-1]);
            }else{
                if(currCard+1 <= 0) currCard = -1;
                y -= (currCard+1);
                System.out.println("Case " + currCase + ": " + cards[y+26]);
            }

            ++currCase;
        }
    }
}
