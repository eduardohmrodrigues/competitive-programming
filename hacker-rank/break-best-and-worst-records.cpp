vector<int> breakingRecords(vector<int> scores) {
    int minR = scores[0], maxR = scores[0], breakMin = 0, breakMax = 0;
    
    for(int i=1; i<scores.size(); ++i) {
        if(scores[i] < minR) {
            minR = scores[i];
            ++breakMin;
        }
        
        if(scores[i] > maxR) {
            maxR = scores[i];
            ++breakMax;
        }
    }
    
    return {breakMax, breakMin};
}
