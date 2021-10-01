import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int s = scanner.nextInt(), b = scanner.nextInt(), l, r, indexOfL, indexOfR, aux;

        while(s != 0 || b != 0) {
            LinkedList<Integer> soldiers = new LinkedList<Integer>();
            for(int i=0; i<s; ++i) soldiers.add(i, i+1);

            for(int i=0; i<b; ++i){
                l = scanner.nextInt();
                r = scanner.nextInt();

                indexOfL = soldiers.indexOf(l);
                indexOfR = soldiers.indexOf(r);
                System.out.print(indexOfL > 0 ? soldiers.get(indexOfL-1) : "*");
                System.out.print(" ");
                System.out.println(indexOfR < soldiers.size()-1 ? soldiers.get(indexOfR+1) : "*");

                aux = indexOfR - indexOfL;
                while(aux-- >= 0){
                    soldiers.remove(indexOfL);
                }
            }
            System.out.println("-");
            s = scanner.nextInt(); b = scanner.nextInt();
        }

    }
}
