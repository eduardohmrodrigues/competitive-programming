import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        List<Character> scoreboard;
        int score, points;
        double amountOfPlays;
        char play;

        while(!line.equals("Game Over")) {
            score = 0;
            amountOfPlays = 0;
            scoreboard = Arrays.stream(line.split("\\s+"))
                        .map(x -> x.charAt(0))
                        .collect(Collectors.toList());

            for(int i = 0; i< scoreboard.size(); ++i){
                play = scoreboard.get(i);
                points = getPoints(play, i, scoreboard);

                if(play == 'X') amountOfPlays += 1d;
                else amountOfPlays += 0.5d;

                if(amountOfPlays < 10) {
                    if(play == 'X') points += getPoints(scoreboard.get(i+1), i+1, scoreboard) + getPoints(scoreboard.get(i+2), i+2, scoreboard);
                    else if(play == '/') points += getPoints(scoreboard.get(i+1), i+1, scoreboard);
                }

                score += points;
            }

            System.out.println(score);
            line = scanner.nextLine();
        }
    }

    public static int getPoints(char play, int i, List<Character> scoreboard) {
        int points;
        if(play == 'X') {
            points = 10;
        }else if(play == '/') {
            points = 10 - (scoreboard.get(i-1) - '0');
        }else{
            points = play - '0';
        }

        return points;
    }
}
