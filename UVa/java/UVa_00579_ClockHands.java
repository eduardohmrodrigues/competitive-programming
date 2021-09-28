import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double p1, p2, aux, degreeOffset;
        String line = scanner.nextLine();
        String[] splt;

        while(!line.equals("0:00")) {
            splt = line.split(":");
            p1 = Integer.parseInt(splt[0]);
            p2 = Integer.parseInt(splt[1]);
            degreeOffset = (p2/60.0d)*30;
            p2 *= 6;
            p1 = p1*30 + degreeOffset;

            aux = p1 - p2;
            aux *= aux < 0 ? -1 : 1;
            aux = aux > 180 ? 360-aux : aux;

            System.out.println(String.format("%.3f", aux));
            line = scanner.nextLine();
        }
    }
}
