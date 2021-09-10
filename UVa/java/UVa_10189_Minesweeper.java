import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> board = new ArrayList<String>();
        String line;
        int field = 1;

        int m, n;
        n = scanner.nextInt();
        m = scanner.nextInt();
        scanner.nextLine();

        while(m != 0){
            if(field > 1) System.out.println();
            board.clear();

            for(int i=0; i<n; ++i){
                board.add(i, scanner.nextLine());
            }

            System.out.println("Field #" + field + ":");
            for(int i=0; i<n; ++i){
                line = "";
                for(int j=0; j<m; ++j){
                    if(board.get(i).charAt(j) == '*') {
                        line = line.concat("*");
                    }else{
                        line = line.concat(getAmount(board, i, j) + "");
                    }
                }

                System.out.println(line);
            }

            n = scanner.nextInt();
            m = scanner.nextInt();
            scanner.nextLine();
            ++field;
        }
    }

    public static int getAmount(List<String> board, int x, int y){
        int amount = 0;

        for(int i=x-1; i<=x+1;++i){
            if(i<0 || i>=board.size()) continue;

            for(int j=y-1; j<=y+1; ++j){
                if(j<0 || j>=board.get(i).length()) continue;
                if(i == x && j == y) continue;

                if(board.get(i).charAt(j) == '*') ++amount;
            }
        }

        return amount;
    }
}
