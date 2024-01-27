/*
* Complete the 'arrayManipulation' function below.
*
* The function is expected to return a LONG_INTEGER.
* The function accepts following parameters:
*  1. INTEGER n
*  2. 2D_INTEGER_ARRAY queries
*/

public static long arrayManipulation(int n, List<List<Integer>> queries) {
    long arr[] = new long[n+1];
    long max = 0;
    
    for(int i=0; i<queries.size(); ++i) {
        int a = queries.get(i).get(0);
        int b = queries.get(i).get(1);
        int k = queries.get(i).get(2);
        arr[a] += k;
        if(b+1 <= n) arr[b+1] -= k;
    }
    
    long curr = 0;
    for(int i=1; i<=n; ++i) {
        curr += arr[i];
        max = max > curr ? max : curr;
    }
    
    return max;
}