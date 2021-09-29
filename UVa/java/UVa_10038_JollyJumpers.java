import java.util.BitSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t, n, a, b, sub;
        boolean jolly;
        while (scanner.hasNext()){
            n = scanner.nextInt();
            BitSet bs = new BitSet(n);
            t = n-1;
            a = scanner.nextInt();

            while(t-- > 0){
                b = scanner.nextInt();
                sub = Math.abs(a-b);

                if(sub < n){
                    bs.set(sub);
                }

                a = b;
            }

            jolly = true;
            for(int i=1; i<n && n>1 && jolly; ++i){
                jolly &= bs.get(i);
            }

            System.out.println(jolly ? "Jolly" : "Not jolly");
            scanner.nextLine();
        }
    }
}
