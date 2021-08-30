#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int calculateSum(std::string str){
	int sum = 0;
	int temp = 0 + 'a';
	
	for(int i=0; i<str.length(); i++){
		if(str[i] >= 'a' && str[i] <= 'z') sum += ((str[i] - 'a')+1);
	}
	
	return sum;
}

int reduce(int x){
	int r = 0;

	while(x != 0){
//		std::cout << "Vou reduzir " << x << " com sum = " << r << std::endl;
		if(x%10 == x){
			r+=x;
			x = 0;
		}else{
			r += x%10;
			x = x/10;
		}

		if(x == 0 && r/10 > 0){
			x = r;
			r = 0;
		}

//		std::cout << "Reduzi para " << x << " com sum = " << r << std::endl;
	}

	return r;
}

int main(){
	std::string n1, n2;
	int p1, p2;
	float percentage;

	while(std::getline(std::cin, n1) && std::getline(std::cin, n2)){
		std::transform(n1.begin(), n1.end(), n1.begin(), [](unsigned char c){return std::tolower(c); });	
		std::transform(n2.begin(), n2.end(), n2.begin(), [](unsigned char c){return std::tolower(c); });	

		p1 = calculateSum(n1);
		p2 = calculateSum(n2);

//		std::cout << "P1Bef = " << p1 << std::endl;
//		std::cout << "P2Bef = " << p2 << std::endl;
		p1 = reduce(p1);
		p2 = reduce(p2);
//		std::cout << "P1Aft = " << p1 << std::endl;
//		std::cout << "P2Aft = " << p2 << std::endl;
		
		if(p1 < p2){
			printf("%.2lf %%\n", 100.0*(double)p1/(double)p2);
		}else{
			printf("%.2lf %%\n", 100.0*(double)p2/(double)p1);
		}
	}
}
