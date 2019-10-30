#include <cstdio>
#include <map>
#include <iostream>
#include <vector>

int main(){
	int n, moneySpent, amountOfPeople;
	std::string giverName, targetName;
	
	std::map<std::string, int> people;
	std::vector<std::string> orderedPeople;
	int ind = 0;

	while(scanf("%d", &n) != EOF){
		if(ind > 0) std::cout << std::endl;
		people.clear();
		orderedPeople.clear();

		for(int i=0; i<n; i++){
			std::cin >> giverName;
			people[giverName] = 0;
			orderedPeople.push_back(giverName);
		}

		for(int i=0; i<n; i++){
			std::cin >> giverName;
			scanf("%d %d", &moneySpent, &amountOfPeople);
			if(amountOfPeople > 0) people[giverName] -= (moneySpent/amountOfPeople)*amountOfPeople;

			for(int j=0; j<amountOfPeople; j++){
				std::cin >> targetName;
				people[targetName] += moneySpent/amountOfPeople;
			}
		}
		
		for(int i=0; i<orderedPeople.size(); i++){
			std::cout << orderedPeople[i] << " " << people[orderedPeople[i]] << std::endl;
		}

		ind++;
	}

	return 0;
}
