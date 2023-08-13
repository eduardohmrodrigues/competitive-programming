// https://www.hackerrank.com/challenges/compare-the-triplets/problem
public static List<Integer> compareTriplets(List<Integer> a, List<Integer> b) {
    int as = 0, bs = 0, currA, currB;
    
    for(int i=0; i<3; ++i) {
        currA = a.get(i);
        currB = b.get(i);
        if(currA > currB) {
            ++as;
        } else if(currB > currA) {
            ++bs;
        }
    }

    return Arrays.asList(as, bs);
}