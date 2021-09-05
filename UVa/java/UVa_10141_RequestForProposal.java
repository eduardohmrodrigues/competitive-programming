import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class Company {
    public String name;
    public double price;
    public double compliance;

    public Company(String name, double price, double compliance) {
        this.name = name;
        this.price = price;
        this.compliance = compliance;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int requirements, proposals, currMetRequirements, currCase = 1;
        double currPrice, compliance, biggestCompliance, lowestPrice;
        List<Company> orderedProposers = new ArrayList<>();
        Company aux;
        String proposerName;

        requirements = scanner.nextInt();
        proposals = scanner.nextInt();
        scanner.nextLine();
        while (requirements != 0 && proposals != 0) {
            if(currCase > 1) System.out.println();

            biggestCompliance = -1;
            orderedProposers.clear();
            for(int i=0; i<requirements; ++i) scanner.nextLine();
            for(int i=0; i<proposals; ++i){
                proposerName = scanner.nextLine();
                currPrice = scanner.nextDouble();
                currMetRequirements = scanner.nextInt();
                scanner.nextLine();
                for(int j=0; j<currMetRequirements; ++j) scanner.nextLine();

                compliance = ((double)currMetRequirements)/((double)requirements);
                biggestCompliance = compliance > biggestCompliance ? compliance : biggestCompliance;
                orderedProposers.add(new Company(proposerName, currPrice, compliance));
            }

            double compl = biggestCompliance;
            orderedProposers = orderedProposers.stream()
                    .filter(x -> x.compliance >= compl)
                    .collect(Collectors.toList());

            lowestPrice = Double.MAX_VALUE;
            for(int i=0; i<orderedProposers.size(); ++i) {
                aux = orderedProposers.get(i);
                lowestPrice = lowestPrice > aux.price ? aux.price : lowestPrice;
            }

            double currLow = lowestPrice;
            orderedProposers = orderedProposers.stream()
                    .filter(x -> x.price <= currLow)
                    .collect(Collectors.toList());

            System.out.println("RFP #" + currCase);
            System.out.println(orderedProposers.get(0).name);

            ++currCase;
            requirements = scanner.nextInt();
            proposals = scanner.nextInt();
            scanner.nextLine();
        }
    }
}
