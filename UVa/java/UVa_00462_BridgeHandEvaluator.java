import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line, currCard;
        String[] cards;
        int points, bonusPoint, cardAmount;
        boolean noTrump;
        char selectedBid;
        Map<Character, Set<Character>> hand = new HashMap<Character, Set<Character>>();
        hand.put('S', new HashSet<Character>());
        hand.put('H', new HashSet<Character>());
        hand.put('D', new HashSet<Character>());
        hand.put('C', new HashSet<Character>());

        while(scanner.hasNextLine()) {
            hand.get('S').clear();
            hand.get('H').clear();
            hand.get('D').clear();
            hand.get('C').clear();

            line = scanner.nextLine();
            cards = line.split("\\s+");
            for(int i=0; i<13; ++i){
                currCard = cards[i];
                hand.get(currCard.charAt(1)).add(currCard.charAt(0));
            }

            points = calculateHand(hand);
            bonusPoint = calculateBonusPoints(hand);
            noTrump = isNoTrump(hand, points);

            if(points + bonusPoint < 14) System.out.println("PASS");
            else if(noTrump) System.out.println("BID NO-TRUMP");
            else{
                selectedBid = 'S';
                cardAmount = hand.get('S').size();

                if(hand.get('H').size() > cardAmount) {
                    selectedBid = 'H';
                    cardAmount = hand.get('H').size();
                }

                if(hand.get('D').size() > cardAmount) {
                    selectedBid = 'D';
                    cardAmount = hand.get('D').size();
                }

                if(hand.get('C').size() > cardAmount) {
                    selectedBid = 'C';
                }

                System.out.println("BID " + selectedBid);
            }
        }
    }

    public static int calculateHand(Map<Character, Set<Character>> hand){
        int points = 0;

        // Each ace counts 4 points. Each king counts 3 points. Each queen counts 2 points. Each jack
        // counts one point.
        points += 4*hand.keySet().stream()
            .filter(key -> hand.get(key).contains('A'))
            .count();

        points += 3*hand.keySet().stream()
                .filter(key -> hand.get(key).contains('K'))
                .count();

        points += 2*hand.keySet().stream()
                .filter(key -> hand.get(key).contains('Q'))
                .count();

        points += hand.keySet().stream()
                .filter(key -> hand.get(key).contains('J'))
                .count();

        // Subtract a point for any king of a suit in which the hand holds no other cards.
        points -= hand.keySet().stream()
                .filter(key -> hand.get(key).contains('K'))
                .filter(suit -> hand.get(suit).size() == 1)
                .count();

        // Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
        points -= hand.keySet().stream()
                .filter(key -> hand.get(key).contains('Q'))
                .filter(suit -> hand.get(suit).size() <= 2)
                .count();

        // Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
        points -= hand.keySet().stream()
                .filter(key -> hand.get(key).contains('J'))
                .filter(suit -> hand.get(suit).size() <= 3)
                .count();

        return points;
    }

    public static int calculateBonusPoints(Map<Character, Set<Character>> hand){
        int points = 0;

        // Add a point for each suit in which the hand contains exactly two cards.
        points += hand.keySet().stream()
                .filter(suit -> hand.get(suit).size() == 2)
                .count();

        // Add two points for each suit in which the hand contains exactly one card.
        // Add two points for each suit in which the hand contains no cards.
        points += 2*hand.keySet().stream()
                .filter(suit -> hand.get(suit).size() <= 1)
                .count();

        return points;
    }

    public static boolean isNoTrump(Map<Character, Set<Character>> hand, int basePoints) {
        return basePoints > 15 && hand.keySet().stream()
                .filter(key -> isStoped(hand.get(key)))
                .count() == 4;
    }

    public static boolean isStoped(Set<Character> set) {
        return set.contains('A') || (set.contains('K') && set.size() > 1) || (set.contains('Q') && set.size() > 2);
    }
}
