import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int participantsAmount, budget, hotelsAmount, weeks, dayPriceCapita, beds;
        long minCost, currCost;
        boolean hotelFound;
        String line = in.readLine();
        String[] bedsStr;

        while(line != null){
            hotelFound = false;
            minCost = Long.MAX_VALUE;
            String[] tmp = line.split("\\s+");
            participantsAmount = Integer.parseInt(tmp[0]);
            budget = Integer.parseInt(tmp[1]);
            hotelsAmount = Integer.parseInt(tmp[2]);
            weeks = Integer.parseInt(tmp[3]);

            for(int i=0; i<hotelsAmount; ++i) {
                dayPriceCapita = Integer.parseInt(in.readLine());
                currCost = dayPriceCapita*participantsAmount;
                bedsStr = in.readLine().split("\\s+");
                for(int j=0; j<weeks; j++) {
                    beds = Integer.parseInt(bedsStr[j]);
                    if(beds >= participantsAmount) {
                        hotelFound = true;
                        minCost = Long.min(minCost, currCost);
                    }
                }
            }

            if(hotelFound && minCost <= budget) System.out.println(minCost);
            else System.out.println("stay home");

            line = in.readLine();
        }
    }
}
