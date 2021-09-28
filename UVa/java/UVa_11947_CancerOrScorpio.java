import java.time.LocalDate;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), addDays = 40*7, dd, mm, yy, index = 1;
        scanner.nextLine();
        String line, sign = "";

        while (n-- > 0) {
            line = scanner.nextLine();
            mm = Integer.parseInt(line.substring(0, 2));
            dd = Integer.parseInt(line.substring(2, 4));
            yy = Integer.parseInt(line.substring(4, 8));
            LocalDate date = LocalDate.of(yy, mm, dd);
            date = date.plusDays(addDays);
            sign = getSign(date);

            System.out.println(index + " "
                    + (date.getMonthValue() < 10 ? "0" : "") + date.getMonthValue()
                    + "/" + (date.getDayOfMonth() < 10 ? "0" : "") + date.getDayOfMonth()
                    + "/" + date.getYear()
                    + " " + sign);
            ++index;
        }
    }

    public static String getSign(LocalDate date) {
            if(date.isBefore(LocalDate.of(date.getYear(), 1, 21))) {
                return "capricorn";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 2, 20))) {
                return "aquarius";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 3, 21))) {
                return "pisces";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 4, 21))) {
                return "aries";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 5, 22))) {
                return "taurus";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 6, 22))) {
                return "gemini";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 7, 23))) {
                return "cancer";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 8, 22))) {
                return "leo";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 9, 24))) {
                return "virgo";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 10, 24))) {
                return "libra";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 11, 23))) {
                return "scorpio";
            }else if(date.isBefore(LocalDate.of(date.getYear(), 12, 23))) {
                return "sagittarius";
            }else{
                return "capricorn";
            }
    }
}
