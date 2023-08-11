// https://www.hackerrank.com/challenges/2d-array/problem
public static int hourglassSum(List<List<Integer>> arr) {
    int max = Integer.MIN_VALUE;
    int sum;

    for(int i=1; i<arr.size()-1; ++i) {
        for(int j=1; j<arr.size()-1; ++j) { 
            sum = arr.get(i-1).get(j-1) + 
                arr.get(i-1).get(j) + 
                arr.get(i-1).get(j+1) +
                arr.get(i).get(j) +
                arr.get(i+1).get(j-1) + 
                arr.get(i+1).get(j) + 
                arr.get(i+1).get(j+1);
            max = Integer.max(max, sum);
        }
    }
    
    return max;
}
