import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Double> depreciationPerMonth = new ArrayList<>(110);
        int duration, depreciationRecordsAmount, month, index;
        double downPayment, loanAmount, currentCarValue, depreciation, valueOwed, monthly;
        duration = scanner.nextInt();

        while(duration > 0) {
            downPayment = scanner.nextDouble();
            loanAmount = scanner.nextDouble();
            currentCarValue = downPayment + loanAmount;
            depreciationRecordsAmount = scanner.nextInt();
            monthly = loanAmount/duration;
            depreciationPerMonth.clear();

            month = scanner.nextInt();
            depreciation = scanner.nextDouble();
            depreciationPerMonth.add(0, depreciation);
            index = 1;
            for(int i=1; i<depreciationRecordsAmount; ++i) {
                month = scanner.nextInt();
                for(; index<month; index++) {
                    depreciationPerMonth.add(index, depreciation);
                }
                index = month;
                depreciation = scanner.nextDouble();
                depreciationPerMonth.add(index++, depreciation);
            }

            for(int i=month+1; i<=duration; ++i){
                depreciationPerMonth.add(i, depreciation);
            }

            for(int i=0; i<=duration; ++i) {
                currentCarValue = currentCarValue - currentCarValue*depreciationPerMonth.get(i);
                valueOwed = (duration-i)*monthly;

                if(valueOwed < currentCarValue || i == duration) {
                    System.out.println(i + " month" + (i == 1 ? "" : "s"));
                    i = duration;
                }
            }

            duration = scanner.nextInt();
        }

    }
}
