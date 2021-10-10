import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(), n = scanner.nextInt(), match0, match90, match180, match270;
        scanner.nextLine();

        List<String> m1 = new ArrayList<String>();
        List<String> m2 = new ArrayList<String>();

        while(N > 0) {
            m1.clear(); m2.clear();
            match0 = 0; match90 = 0; match180 = 0; match270 = 0;

            for(int i=0; i<N; ++i) m1.add(scanner.nextLine());
            for(int i=0; i<n; ++i) m2.add(scanner.nextLine());

            for(int i=0; i<=N-n; ++i){
                for(int j=0; j<=N-n; ++j){
                    match0 += m0(m1, m2, i, j);
                    match90 += m90(m1, m2, i, j);
                    match180 += m180(m1, m2, i, j);
                    match270 += m270(m1, m2, i, j);
                }
            }

            System.out.println(String.format("%d %d %d %d", match0, match90, match180, match270));

            N = scanner.nextInt(); n = scanner.nextInt();
            scanner.nextLine();
        }
    }

    private static int m0(List<String> m1, List<String> m2, int x, int y) {
        boolean match = true;

        //-=-=-=-=-=-LEFT -> RIGHT-=-=-=-=-=-
        for(int i=0; i<m2.size(); ++i){
            for(int j=0; j<m2.size() && match; ++j){
                match &= m1.get(x+i).charAt(y+j) == m2.get(i).charAt(j);
            }
        }

        return match ? 1 : 0;
    }

    private static int m90(List<String> m1, List<String> m2, int x, int y) {
        boolean match = true;

        //-=-=-=-=-=-BOTTOM -> UP-=-=-=-=-=-
        for(int j=0; j<m2.size(); ++j){
            for(int i=m2.size()-1; i>=0 && match; --i){
                char c1 = m1.get(x+j).charAt(y+(m2.size()-i-1));
                char c2 = m2.get(i).charAt(j);
                match &= c1 == c2;
            }
        }

        return match ? 1 : 0;
    }

    private static int m180(List<String> m1, List<String> m2, int x, int y) {
        boolean match = true;

        //-=-=-=-=-=-RIGHT -> LEFT-=-=-=-=-=-
        for(int i=m2.size()-1; i>=0; --i){
            for(int j=m2.size()-1; j>=0 && match; --j){
                char c1 = m1.get(x+(m2.size()-i-1)).charAt(y+(m2.size()-j-1));
                char c2 = m2.get(i).charAt(j);
                match &= c1 == c2;
            }
        }

        return match ? 1 : 0;
    }

    private static int m270(List<String> m1, List<String> m2, int x, int y) {
        boolean match = true;

        //-=-=-=-=-=-TOP -> DOWN-=-=-=-=-=-
        for(int j=m2.size()-1; j>=0; --j){
            for(int i=0; i<m2.size() && match; ++i){
                match &= m1.get(x + (m2.size()-j-1)).charAt(y+i) == m2.get(i).charAt(j);
            }
        }

        return match ? 1 : 0;
    }
}
