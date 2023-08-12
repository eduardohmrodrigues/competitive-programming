// https://www.hackerrank.com/challenges/lonely-integer/
public static int lonelyinteger(List<Integer> a) {
    // Write your code here
    Map<Integer, Integer> existent = new HashMap();
    int unique = 0, curr;

    for(int i=0; i<a.size(); ++i) {
        curr = a.get(i);

        existent.putIfAbsent(curr, 0);
        existent.put(curr, existent.get(curr)+1);
    }

    for(int i=0; i<a.size(); ++i) {
        curr = a.get(i);
        if(existent.get(curr) == 1) {
            unique = curr;
        }
    }

    return unique;
}
