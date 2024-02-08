void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int appleCount = 0, orangeCount = 0;
    int fallPos;
    
    for(int i=0; i<apples.size(); ++i) {
        fallPos = a + apples[i];
        if(fallPos >= s && fallPos <= t) ++appleCount;
    }
    
    for(int i=0; i<oranges.size(); ++i) {
        fallPos = b + oranges[i];
        if(fallPos >= s && fallPos <= t) ++orangeCount;
    }
    
    cout << appleCount << endl << orangeCount << endl;
}
