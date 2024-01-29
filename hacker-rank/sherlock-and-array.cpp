/*
 * Complete the 'balancedSums' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string balancedSums(vector<int> arr) {
    vector<int> left(arr.size()), right(arr.size());
    int sumL = 0, sumR = 0;

    for(int i=1; i<arr.size(); ++i) {
        sumL += arr[i-1];
        sumR += arr[arr.size()-i];
        left[i] = sumL;
        right[arr.size()-i-1] = sumR;
    }
    for(int i=0; i<arr.size(); ++i)
        if(left[i] == right[i]) return "YES";
    
    return "NO";
}
