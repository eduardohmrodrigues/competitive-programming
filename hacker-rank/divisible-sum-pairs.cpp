int divisibleSumPairs(int n, int k, vector<int> ar) {
    map<int, vector<int>> numbers;
    int numberOfPairs = 0, curr;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            curr = ar[i] + ar[j];
            if(curr%k == 0) ++numberOfPairs;
        }
    }

    return numberOfPairs;
}
