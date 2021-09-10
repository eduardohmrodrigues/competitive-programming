import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int round = scanner.nextInt();
        scanner.nextLine();
        String solution, guess;
        char current;
        Set<Character> expected = new HashSet<Character>();
        Set<Character> correct = new HashSet<Character>();
        Set<Character> errors = new HashSet<Character>();

        while (round != -1) {
            expected.clear();
            correct.clear();
            errors.clear();
            solution = scanner.nextLine();
            guess = scanner.nextLine();

            for(int i=0; i<solution.length(); ++i){
                expected.add(solution.charAt(i));
            }

            for(int i=0; i<guess.length() && errors.size() < 7 && correct.size() != expected.size(); ++i){
                current = guess.charAt(i);

                if(expected.contains(current)) {
                    correct.add(current);
                }else if(!errors.contains(current)){
                    errors.add(current);
                }
            }

            System.out.println("Round " + round);
            if(correct.size() == expected.size()){
                System.out.println("You win.");
            }else if(errors.size() == 7) {
                System.out.println("You lose.");
            }else{
                System.out.println("You chickened out.");
            }

            round = scanner.nextInt();
            scanner.nextLine();
        }
    }
}
