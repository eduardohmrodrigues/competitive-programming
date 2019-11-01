#include <cstdio>
#include <iostream>

int main(){
	int shotheight[50];
	int n, s, damage;
	std::string kiloman;
	scanf("%d", &n);

	while(n--){
		damage = 0;
		scanf("%d", &s);

		for(int i=0; i<s; i++) scanf("%d", &shotheight[i]);
		
		std::cin >> kiloman;
		for(int i=0; i<s; i++){
			if(shotheight[i] < 3 && kiloman[i] == 'S') damage++;
			if(shotheight[i] > 2 && kiloman[i] == 'J') damage++;
		}

		printf("%d\n", damage);
	}
}
