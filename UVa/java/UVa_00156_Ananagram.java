import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String curr, ordered, line = scanner.nextLine();
        SortedSet<String> dictionary = new TreeSet<>();
        Map<String, Integer> orderedDictionary = new HashMap<String, Integer>();

        while(!line.equals("#")){
            Arrays.stream(line.split("\\s+"))
                    .forEach(x -> {
                        dictionary.add(x);
                        char[] arr = x.toLowerCase().toCharArray();
                        Arrays.sort(arr);
                        String localOrdered = String.valueOf(arr);
                        if(!orderedDictionary.containsKey(localOrdered)) orderedDictionary.put(localOrdered, 0);
                        orderedDictionary.put(localOrdered, orderedDictionary.get(localOrdered)+1);
                    });
            line = scanner.nextLine();
        }

        Iterator<String> it = dictionary.iterator();
        while(it.hasNext()){
            curr = it.next();
            char[] arr = curr.toLowerCase().toCharArray();
            Arrays.sort(arr);
            ordered = String.valueOf(arr);
            if(orderedDictionary.get(ordered) == 1) System.out.println(curr);
        }
    }
}
