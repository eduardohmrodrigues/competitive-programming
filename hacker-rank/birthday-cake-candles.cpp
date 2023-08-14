// https://www.hackerrank.com/challenges/birthday-cake-candles/problem
int birthdayCakeCandles(vector<int> candles) {
    int tallest = 0, counter = 0, curr;
    for(int i=0; i<candles.size(); ++i) {
        curr = candles[i];
        if(curr > tallest) {
            tallest = curr;
            counter = 1;
        } else if(curr == tallest) {
            ++counter;
        }
    }
        
    return counter;
}
