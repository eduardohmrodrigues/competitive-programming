import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine(); scanner.nextLine();
        String line, anagramKey;
        Map<String, List<String>> anagrams = new HashMap<String, List<String>>();
        List<String> words = new ArrayList<String>();

        while(t-- > 0){
            line = scanner.nextLine();
            anagrams.clear();
            words.clear();

            while(!line.isEmpty()){
                words.add(line);
                anagramKey = getAnagramKey(line);
                if(!anagrams.containsKey(anagramKey)) anagrams.put(anagramKey, new ArrayList<String>());
                anagrams.get(anagramKey).add(line);

                line = scanner.nextLine();
            }

            Collections.sort(words);
            for(int i=0; i<words.size(); ++i){
                String word = words.get(i);
                anagramKey = getAnagramKey(word);
                anagrams.get(anagramKey).removeIf(x -> x == word);
                Collections.sort(anagrams.get(anagramKey));

                anagrams.get(anagramKey).forEach(x -> {
                    if(x != word) System.out.println(word + " = " + x);
                });
            }

            if(t != 0) System.out.println();

        }
    }

    public static String getAnagramKey(String word){
        char[] ordered = word.replace(" ", "").toCharArray();
        Arrays.sort(ordered);
        return String.valueOf(ordered);
    }
}
