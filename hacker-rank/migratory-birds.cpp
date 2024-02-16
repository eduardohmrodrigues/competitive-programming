int migratoryBirds(vector<int> arr) {
    vector<int> occ = {0, 0, 0, 0, 0, 0};
    
    for(int i=0; i<arr.size(); ++i) {
        occ[arr[i]] = occ[arr[i]] + 1;
    }
    
    int max = occ[1], index = 1;
    for(int i=2; i<6; ++i) {
        if(occ[i] > max) {
            max = occ[i];
            index = i;
        }
    }
    
    return index;
}
