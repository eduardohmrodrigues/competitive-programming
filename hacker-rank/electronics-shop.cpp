int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    set<int> kset(keyboards.begin(), keyboards.end());
    set<int> dset(drives.begin(), drives.end());
    int max = -1;
    for(auto it=kset.rbegin(); it != kset.rend(); ++it) {
        int curr = *it;
        for(auto dit=dset.rbegin(); dit != dset.rend(); ++dit) {
            int sum = *dit + *it;
            if(sum <= b && sum >= max) max = sum;
            if(sum < max) break;
        }
    }
    return max;
}
