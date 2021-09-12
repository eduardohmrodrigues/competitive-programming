import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<List<Character>> boardToday = new ArrayList<List<Character>>(100);
        List<List<Character>> boardTomorrow = new ArrayList<List<Character>>(100);

        String line;
        int r, c, n, tests = scanner.nextInt();
        boolean first = true;
        char res;
        scanner.nextLine();

        while(tests-- > 0) {
            if(!first) System.out.println();
            boardToday.clear();
            boardTomorrow.clear();

            r = scanner.nextInt();
            c = scanner.nextInt();
            n = scanner.nextInt();
            scanner.nextLine();
            for(int i=0; i<r; ++i) {
                line = scanner.nextLine();
                boardToday.add(new ArrayList<Character>(c));
                boardTomorrow.add(new ArrayList<Character>(c));
                for(int j=0; j<line.length(); ++j){
                    boardToday.get(i).add(line.charAt(j));
                    boardTomorrow.get(i).add(line.charAt(j));
                }
            }

            while(n-- > 0){
                for(int i=0; i<r; ++i){
                    for(int j=0; j<c; ++j){
                        if(i < r-1 && boardToday.get(i).get(j) != boardToday.get(i+1).get(j)){
                           res = getWarResult(boardToday.get(i).get(j), boardToday.get(i+1).get(j));

                           if(res != boardToday.get(i+1).get(j)) {
                               boardTomorrow.get(i+1).set(j, res);
                           }

                           if(res != boardToday.get(i).get(j)){
                               boardTomorrow.get(i).set(j, res);
                           }
                        }
                        if(j < c-1 && boardToday.get(i).get(j) != boardToday.get(i).get(j+1)){
                            res = getWarResult(boardToday.get(i).get(j), boardToday.get(i).get(j+1));
                            if(res != boardToday.get(i).get(j+1)) {
                                boardTomorrow.get(i).set(j+1, res);
                            }
                            if(res != boardToday.get(i).get(j)){
                                boardTomorrow.get(i).set(j, res);
                            }
                        }
                    }
                }

                boardToday.clear();
                for(int i=0; i<r; ++i) {
                    for (int j = 0; j < c; ++j) {
                        boardToday.add(new ArrayList<Character>(c));
                        boardToday.get(i).add(boardTomorrow.get(i).get(j).charValue());
                    }
                }
            }

            for(int i=0; i<r; ++i) {
                for(int j=0; j<c; ++j){
                    System.out.print(boardToday.get(i).get(j) + "");
                }
                System.out.println();
            }
            first = false;
        }
    }

    public static char getWarResult(char a, char b){
        if(a == 'R') {
            if(b == 'P'){
                return 'P';
            }else{
                return 'R';
            }
        }else if(a == 'S'){
            if(b == 'R'){
                return 'R';
            }else{
                return 'S';
            }
        }else{
            if(b == 'S'){
                return 'S';
            }else{
                return 'P';
            }
        }
    }
}
