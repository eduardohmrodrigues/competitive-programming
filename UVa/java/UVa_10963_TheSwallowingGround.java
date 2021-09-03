import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t, w, y1, y2, dist, aux;
        boolean isFirst = true, canFill;
        t = scanner.nextInt();
        scanner.nextLine();

        while(t-- > 0) {
            w = scanner.nextInt();
            isFirst = true;
            canFill = true;
            dist = 0;
            while(w-- > 0) {
                y1 = scanner.nextInt();
                y2 = scanner.nextInt();

                if(!canFill) continue;

                if(isFirst){
                    dist = (y1 - y2) + 1;
                    isFirst = false;
                }else{
                    aux = (y1 - y2) + 1;
                    canFill &= aux == dist;
                }
            }

            System.out.println(canFill ? "yes" : "no");
            if(t > 0) System.out.println();
        }
    }
}
