import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Double> group = new HashMap<String, Double>();
        List<String> orderedNames = new ArrayList<>();
        int n, giftReceiversAmount, money, debt, netWorth;
        boolean firstExecution = true;
        String currPerson;

        while(scanner.hasNextLine()){
            if(!firstExecution) System.out.println();

            group.clear();
            orderedNames.clear();
            n = scanner.nextInt();

            for(int i=0; i<n; ++i){
                currPerson = scanner.next();
                orderedNames.add(currPerson);
                group.put(currPerson, 0d);
            }

            for(int i=0; i<n; ++i){
                currPerson = scanner.next();
                money = scanner.nextInt();
                giftReceiversAmount = scanner.nextInt();

                if(giftReceiversAmount == 0) continue;

                debt = money / giftReceiversAmount;
                netWorth = money - (debt * giftReceiversAmount);
                group.put(currPerson, (group.get(currPerson) - money) + netWorth);

                for(int j=0; j<giftReceiversAmount; ++j){
                    currPerson = scanner.next();
                    group.put(currPerson, group.get(currPerson) + debt);
                }
            }

            for(int i=0; i<n; ++i){
                currPerson = orderedNames.get(i);
                System.out.println( currPerson+ " " + ((int) Math.floor(group.get(currPerson))));
            }

            firstExecution = false;
            scanner.nextLine();
        }
    }
}
