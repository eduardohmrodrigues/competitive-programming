import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int aux, curr, seconds, cycle = scanner.nextInt(), limit = 18001;
        String hrs, mins, secs;
        boolean allGreen;
        List<Integer> cycles = new ArrayList<Integer>();

        while(cycle != 0) {
            cycles.clear();
            cycles.add(cycle);
            cycle = scanner.nextInt();
            while (cycle != 0) {
                cycles.add(cycle);
                cycle = scanner.nextInt();
            }

            cycles.sort(Comparator.naturalOrder());
            seconds = (cycles.get(0)*2);
            allGreen = false;
            for(; seconds<limit && !allGreen;){
                allGreen = true;
                for(int i=0; i<cycles.size() && allGreen; ++i){
                    curr = cycles.get(i);
                    aux = seconds%(curr*2);
                    allGreen &= aux <= (curr-6);
                }

                if(!allGreen) ++seconds;
            }

            if(seconds == limit) System.out.println("Signals fail to synchronise in 5 hours");
            else {
                hrs = "0" + (seconds/3600);
                mins = String.valueOf((seconds%3600)/60);
                mins = mins.length() == 1 ? "0" + mins : mins;
                secs = String.valueOf(seconds%60);
                secs = secs.length() == 1 ? "0" + secs : secs;
                System.out.println(String.format("%s:%s:%s", hrs, mins, secs));
            }

            cycle = scanner.nextInt();
        }
    }
}
