import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String line;
        int unitDegree = 9;

        while(scanner.hasNextLine()){
            line = scanner.nextLine();
            List<Integer> pos = Arrays.stream(line.split("\\s+"))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());

            if(pos.stream().filter(x -> x != 0).count() == 0) return;

            int first = pos.get(0) - pos.get(1);
            first = first < 0 ? (40 + first) : first;

            int second = pos.get(2) - pos.get(1);
            second = second < 0 ? (40 + second) : second;

            int third = pos.get(2) - pos.get(3);
            third = third < 0 ? (40 + third) : third;

            System.out.println(720 + first*unitDegree + 360 + second*unitDegree + third*unitDegree);
        }
    }
}
