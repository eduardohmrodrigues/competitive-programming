import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t, m, n;
        String piece;
        t = scanner.nextInt();

        while(t-- > 0){
            piece = scanner.next();
            m = scanner.nextInt();
            n = scanner.nextInt();

            if(piece.equals("k")){
                System.out.println(((int) Math.ceil(m*n/2.0)));
            }else if(piece.equals("r")){
                System.out.println(Math.min(m, n));
            }else if(piece.equals("Q")){
                System.out.println(Math.min(m, n));
            }else{
                System.out.println(((int) Math.ceil(m/2.0))*((int)Math.ceil(n/2.0)));
            }
        }
    }
}
