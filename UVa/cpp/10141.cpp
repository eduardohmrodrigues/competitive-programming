#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

struct RFP{
	std::string name;
	double price;
	int metRequirements;
	double compliance;
	int index;
};

bool compare(const RFP &a, const RFP &b){
	if(a.compliance > b.compliance){
		return true;
	}else if(a.compliance < b.compliance){
		return false;
	}else{
		if(a.price < b.price){
			return true;
		}else if(a.price > b.price){
			return false;
		}else{
			return a.index < b.index;
		}
	}
}

int main(){
	int n, p, index = 1;
	std::vector<RFP> proposals;
	
	while(scanf("%d %d%*c", &n, &p) && n != 0 && p != 0){
//		std::cout << "N = " << n << " P = " << p << std::endl;
		std::string garbageStr, companyName;
		int metRequirements;
		double price;
		proposals.clear();

		for(int i=0; i<n; i++){
			 std::getline(std::cin, garbageStr);
//			 std::cout << "N" << i << " = " << garbageStr << std::endl;
		}

		for(int i=0; i<p; i++){
			std::getline(std::cin, companyName);
			scanf("%lf %d%*c", &price, &metRequirements);
//			std::cout << "Company: " << companyName << " Price: "<< price << " Met: " << metRequirements << std::endl;
			for(int j=0; j<metRequirements; j++){
				 std::getline(std::cin, garbageStr);
//				 std::cout << "Met" << j << " = " << garbageStr << std::endl;
			}
			
			RFP rfp = {.name = companyName, .price = price, .metRequirements = metRequirements, .compliance = ((float)metRequirements)/((float)n), .index = i};
			proposals.push_back(rfp);
		}
		
		std::sort(proposals.begin(), proposals.end(), compare);
		if(index > 1) std::cout << std::endl;
		std::cout << "RFP #" << index << std::endl << proposals[0].name << std::endl;
		++index;
	}

	return 0;
}
