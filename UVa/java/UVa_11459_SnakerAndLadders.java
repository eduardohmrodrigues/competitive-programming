import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int testCases, a, b, c, tmp, aux, pos;
        List<Integer> players = new ArrayList<Integer>(1000005);
        Map<Integer, Integer> ladders = new HashMap<Integer, Integer>(105);
        boolean gameEnded;

        testCases = scanner.nextInt();
        while(testCases-- > 0){
            gameEnded = false;
            players.clear();
            ladders.clear();
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();

            for(int i=0; i<a; ++i) players.add(i, 1);
            for(int i=0; i<b; ++i){
                // bottom of ladder
                tmp = scanner.nextInt();
                // top of ladder
                aux = scanner.nextInt();
                ladders.put(tmp, aux);
            }

            // current player
            aux = 0;
            for(int i=0; i<c; ++i){
                // die roll
                pos = players.get(aux);
                tmp = scanner.nextInt();

                if(gameEnded) continue;

                pos = Math.min(pos+tmp, 100);
                if(ladders.containsKey(pos)) pos = ladders.get(pos);

                if(pos == 100){
                    gameEnded = true;
                }

                players.set(aux, pos);
                aux = (aux+1) == a ? 0 : aux+1;
            }

            for(int i=0; i<a; ++i){
                System.out.println("Position of player " + (i+1) + " is " + players.get(i) + ".");
            }
        }
    }
}
