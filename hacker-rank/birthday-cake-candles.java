// https://www.hackerrank.com/challenges/birthday-cake-candles/problem
public static int birthdayCakeCandles(List<Integer> candles) {
    int tallest = 0, counter = 0, curr;
    for(int i=0; i<candles.size(); ++i) {
        curr = candles.get(i);
        if(curr > tallest) {
            tallest = curr;
            counter = 1;
        } else if(curr == tallest) {
            ++counter;
        }
    }
    
    return counter;
}
