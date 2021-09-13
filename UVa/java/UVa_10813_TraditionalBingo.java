import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Set<Integer>> bingoLines;
        List<List<Integer>> card = new ArrayList<List<Integer>>(5);
        int number, plays, n = scanner.nextInt();
        boolean finished;
        scanner.nextLine();

        while(n-- > 0) {
            plays = 0;
            finished = false;
            card.clear();

            for(int i=0; i<5; ++i){
               card.add(Arrays.stream(scanner.nextLine().split("\\s+")).map(Integer::parseInt).collect(Collectors.toList()));
            }
            card.get(2).add(2, -1);
            bingoLines = getBingoLines(card);

            for(int i=0; i<75; ++i){
                number = scanner.nextInt();
                if(finished) continue;
                ++plays;
                for(int j=0; j<bingoLines.size(); ++j){
                    int finalNumber = number;
                    bingoLines.get(j).removeIf(x -> x == finalNumber);
                    if(bingoLines.get(j).size() == 0 || (bingoLines.get(j).size() == 1 && bingoLines.get(j).contains(-1))) {
                        finished = true;
                    }
                }
            }
            scanner.nextLine();
            System.out.println("BINGO after " + plays + " numbers announced");
        }
    }

    public static List<Set<Integer>> getBingoLines(List<List<Integer>> card) {
        List<Set<Integer>> bingoLines = new ArrayList<Set<Integer>>();

        // Get Rows
        for(int i=0; i<5; ++i){
            bingoLines.add(new HashSet<Integer>());
            int index = i;
            card.get(i).stream()
                    .forEach(x -> bingoLines.get(index).add(x));
        }

        // Get Columns
        int initialSize = bingoLines.size();
        for(int j=0; j<5; ++j){
            bingoLines.add(new HashSet<Integer>());
            for(int i=0; i<5; ++i){
                bingoLines.get(initialSize+j).add(card.get(i).get(j));
            }
        }

        // Diagonals
        bingoLines.add(new HashSet<Integer>());
        bingoLines.add(new HashSet<Integer>());
        for(int i=0; i<5; ++i){
            // 0,0 to 4,4
            bingoLines.get(bingoLines.size()-2).add(card.get(i).get(i));
            // 0,4 to 4,0
            bingoLines.get(bingoLines.size()-1).add(card.get(i).get(4-i));
        }

        return bingoLines;
    }
}
