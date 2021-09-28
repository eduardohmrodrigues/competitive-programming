import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int addDays = scanner.nextInt(), dd = scanner.nextInt(), mm = scanner.nextInt(), yy = scanner.nextInt();

        while (addDays + dd + mm + yy != 0) {
            LocalDateTime localDateTime = LocalDateTime.of(LocalDate.of(yy, mm, dd), LocalTime.MIN);
            localDateTime = localDateTime.plusDays(addDays);

            System.out.println(localDateTime.getDayOfMonth() + " " + localDateTime.getMonthValue() + " " + localDateTime.getYear());
            addDays = scanner.nextInt();
            dd = scanner.nextInt();
            mm = scanner.nextInt();
            yy = scanner.nextInt();
        }
    }
}
