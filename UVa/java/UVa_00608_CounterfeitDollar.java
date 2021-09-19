import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        String left, right, s;
        int[] weights = new int[15];

        while(t-- > 0) {

            for(int i=0; i<14; ++i) weights[i] = Integer.MIN_VALUE;

            for(int i=0; i<3; ++i) {
                left = scanner.next();
                right = scanner.next();
                s = scanner.next();

                for(int j=0; j<left.length(); ++j){
                    int currL = left.charAt(j)-'A';
                    int currR = right.charAt(j)-'A';
                    if(weights[currL] == Integer.MIN_VALUE) weights[currL] = 0;
                    if(weights[currR] == Integer.MIN_VALUE) weights[currR] = 0;

                    if(s.equals("even")){
                        weights[currL] = Integer.MAX_VALUE;
                        weights[currR] = Integer.MAX_VALUE;
                    }else if(s.equals("up")){
                        if(weights[currL] != Integer.MAX_VALUE) weights[currL] += 1;
                        if(weights[currR] != Integer.MAX_VALUE) weights[currR] -= 1;
                    }else{
                        if(weights[currL] != Integer.MAX_VALUE) weights[currL] -= 1;
                        if(weights[currR] != Integer.MAX_VALUE) weights[currR] += 1;
                    }
                }
            }

            int index = -1, currWeight;
            for(int i=0; i<13; ++i){
                if(weights[i] == Integer.MIN_VALUE || weights[i] == Integer.MAX_VALUE) continue;
                if(index == -1) index = i;
                currWeight = Math.abs(weights[i]);
                index = currWeight > Math.abs(weights[index]) ? i : index;
            }

            System.out.println(((char)(index + 'A')) + " is the counterfeit coin and it is " + (weights[index] < 0 ? "light" : "heavy") + ".");
        }
    }
}
