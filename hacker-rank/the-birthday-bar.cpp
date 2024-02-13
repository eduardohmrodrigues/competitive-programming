int birthday(vector<int> s, int d, int m) {
    if(s.size() < m) return 0;

    int currSum = s[0], possibilities = 0;
    for(int pivotR=1; pivotR<m; ++pivotR) {
        currSum += s[pivotR];
    }
    if(currSum == d) ++possibilities;
    for(int pivotR=m; pivotR<s.size(); ++pivotR) {
        currSum += s[pivotR] - s[pivotR-m];
        if(currSum == d) ++possibilities;
    }
    
    return possibilities;
}
