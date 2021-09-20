import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static class BloodComparator implements Comparator {
        @Override
        public int compare(Object o1, Object o2) {
            String a = (String) o1;
            String b = (String) o2;

            if(a.charAt(0) == 'O'){
                return -1;
            }else if(b.charAt(0) == '0'){
                return 1;
            }
            if(a.length() < b.length()) {
                return 1;
            }else if(a.length() > b.length()){
                return -1;
            }else{
                return -1*a.compareTo(b);
            }
        }
    }

    public static void main(String[] args) {
        Map<String, List<String>> blood2Combination = new HashMap<String, List<String>>();
        blood2Combination.put("A", Arrays.asList("AA", "AO")); blood2Combination.put("B", Arrays.asList("BB", "BO"));
        blood2Combination.put("AB", Arrays.asList("AB")); blood2Combination.put("O", Arrays.asList("OO"));

        Map<String, String> combination2blood = new HashMap<String, String>();
        combination2blood.put("AA", "A"); combination2blood.put("AB", "AB"); combination2blood.put("BA", "AB");
        combination2blood.put("AO", "A"); combination2blood.put("OA", "A"); combination2blood.put("BB", "B");
        combination2blood.put("BO", "B"); combination2blood.put("OB", "B"); combination2blood.put("OO", "O");

        Map<String, List<String>> bloodCell2Provider = new HashMap<String, List<String>>();
        bloodCell2Provider.put("A", Arrays.asList("AA", "AB", "AO"));
        bloodCell2Provider.put("B", Arrays.asList("AB", "BB", "BO"));
        bloodCell2Provider.put("O", Arrays.asList("AO", "BO", "OO"));

        Map<String, String> rh2CombinationProvider = new HashMap<String, String>();
        rh2CombinationProvider.put("+","+-"); rh2CombinationProvider.put("-","--");

        Map<String, List<String>> rh2origin = new HashMap<String, List<String>>();
        rh2origin.put("+", Arrays.asList("+-", "++")); rh2origin.put("-", Arrays.asList("--"));

        Map<String, String> combination2Rh = new HashMap<String, String>();
        combination2Rh.put("++", "+"); combination2Rh.put("+-", "+");
        combination2Rh.put("-+", "+"); combination2Rh.put("--", "-");

        Scanner scanner = new Scanner(System.in);
        int testCase = 1;
        String p1, p2, c, b1, b2, rh1, rh2;
        p1 = scanner.next(); p2 = scanner.next(); c = scanner.next();
        List<String> possibleBlood;
        List<String> possibleRh;

        while(!p1.equals("E")) {
            if(p1.equals("?")){
                b1 = p2.substring(0, p2.length()-1);
                b2 = c.substring(0, c.length()-1);
                rh1 = p2.substring(p2.length()-1);
                rh2 = c.substring(c.length()-1);
            }else if(p2.equals("?")){
                b1 = p1.substring(0, p1.length()-1);
                b2 = c.substring(0, c.length()-1);
                rh1 = p1.substring(p1.length()-1);
                rh2 = c.substring(c.length()-1);
            }else{
                b1 = p1.substring(0, p1.length()-1);
                b2 = p2.substring(0, p2.length()-1);
                rh1 = p1.substring(p1.length()-1);
                rh2 = p2.substring(p2.length()-1);
            }

            if(p1.equals("?")){
                possibleBlood = getPossibleParent(b1, b2, blood2Combination, combination2blood, bloodCell2Provider);
                possibleRh = getPossibleParentRh(rh1, rh2);
                System.out.print("Case " + testCase + ": ");
                printBlood(possibleBlood, possibleRh);
                System.out.println(" " + p2 + " " + c);
            }else if(p2.equals("?")){
                possibleBlood = getPossibleParent(b1, b2, blood2Combination, combination2blood, bloodCell2Provider);
                possibleRh = getPossibleParentRh(rh1, rh2);
                System.out.print("Case " + testCase + ": " + p1 + " ");
                printBlood(possibleBlood, possibleRh);
                System.out.println(" " + c);
            }else{
                possibleBlood = getPossibleChild(b1, b2, blood2Combination, combination2blood);
                possibleRh = getPossibleChildRh(rh1, rh2, rh2CombinationProvider, combination2Rh);
                System.out.print("Case " + testCase + ": " + p1 + " " + p2 + " ");
                printBlood(possibleBlood, possibleRh);
                System.out.println();
            }

            p1 = scanner.next(); p2 = scanner.next(); c = scanner.next();
            ++testCase;
        }
    }

    public static List<String> getPossibleChild(String parentBlood1, String parentBlood2,
                                                Map<String, List<String>> blood2Combination, Map<String, String> combination2blood) {
        Set<String> childCombinations = new HashSet<String>();
        List<String> p1Comb = blood2Combination.get(parentBlood1);
        List<String> p2Comb = blood2Combination.get(parentBlood2);
        String p1, p2;

        for(int i=0; i<p1Comb.size(); ++i) {
            p1 = p1Comb.get(i);
            for(int j=0; j<p2Comb.size(); ++j){
                p2 = p2Comb.get(j);
                for(int k=0; k<p1.length(); ++k){
                    for(int l=0; l<p2.length(); ++l){
                        childCombinations.add(String.valueOf(p1.charAt(k)) + String.valueOf(p2.charAt(l)));
                    }
                }
            }
        }

        List<String> childBlood = (List<String>) childCombinations.stream()
                .map(x -> combination2blood.get(x))
                .collect(Collectors.toSet())
                .stream()
                .sorted(new BloodComparator())
                .collect(Collectors.toList());
        return childBlood;
    }

    public static List<String> getPossibleParent(String parentBlood, String childBlood,
                                                 Map<String, List<String>> blood2Combination, Map<String, String> combination2blood,
                                                 Map<String, List<String>> bloodCell2Provider){
        List<String> childCombination = blood2Combination.get(childBlood);
        List<String> parentCombinations = blood2Combination.get(parentBlood);
        Set<String> possibleParents = new HashSet<>();

        for(int i=0; i<childCombination.size(); ++i){
            Set<String> p1 = bloodCell2Provider.get(String.valueOf(childCombination.get(i).charAt(0))).stream().collect(Collectors.toSet());
            Set<String> p2 = bloodCell2Provider.get(String.valueOf(childCombination.get(i).charAt(1))).stream().collect(Collectors.toSet());

            boolean parentCanBeP1 = parentCombinations.stream().filter(x -> p1.contains(x)).count() > 0;
            boolean parentCanBeP2 = parentCombinations.stream().filter(x -> p2.contains(x)).count() > 0;

            if(parentCanBeP1) {
                possibleParents.addAll(p2);
            }
            if(parentCanBeP2) {
                possibleParents.addAll(p1);
            }
        }

        return (List<String>) possibleParents
                .stream()
                .map(x -> combination2blood.get(x))
                .collect(Collectors.toSet())
                .stream()
                .sorted(new BloodComparator())
                .collect(Collectors.toList());
    }

    public static List<String> getPossibleChildRh(String rh1, String rh2,
                                                  Map<String, String> rh2CombinationProvider, Map<String, String> combination2rh) {
        Set<String> childCombination = new HashSet<String>();
        String p1Comb = rh2CombinationProvider.get(rh1);
        String p2Comb = rh2CombinationProvider.get(rh2);
        char p1, p2;
        for(int i=0; i<p1Comb.length(); ++i) {
            p1 = p1Comb.charAt(i);
            for(int j=0; j<p2Comb.length(); ++j) {
                p2 = p2Comb.charAt(j);
                childCombination.add(String.valueOf(p1) + String.valueOf(p2));
            }
        }

        return childCombination.stream()
                .map(x -> combination2rh.get(x))
                .collect(Collectors.toSet())
                .stream()
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.toList());
    }

    public static List<String> getPossibleParentRh(String parentRh, String childRh) {

        List<String> aux = new ArrayList<String>();
        if(parentRh.equals("-")){
            if(childRh.equals("+")){
                aux.add("+");
            }else{
                aux.add("-");
                aux.add("+");
            }
        }else{
            aux.add("-");
            aux.add("+");
        }

        return aux;
    }

    public static void printBlood(List<String> bloodType, List<String> rhs) {
        if(bloodType.size() == 0 || rhs.size() == 0) {
            System.out.print("IMPOSSIBLE");
            return;
        }

        if(bloodType.size() > 1 || rhs.size() > 1) System.out.print("{");
        for(int i=0; i<bloodType.size(); ++i){
            for(int j=0; j<rhs.size(); ++j){
                System.out.print(bloodType.get(i) + rhs.get(j));
                if(j+1 < rhs.size()) System.out.print(", ");
            }
            if(i+1 < bloodType.size()) System.out.print(", ");
        }
        if(bloodType.size() > 1 || rhs.size() > 1) System.out.print("}");
    }
}
