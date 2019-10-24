#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>

int main(){
	int nc, n, k, pointer;
	int caseNumber = 1;

	scanf("%d", &nc);
	while(nc > 0){
		pointer = 0;
		scanf("%d %d", &n, &k);
		k -= 1;

		std::vector<int> people(n+1);
		std::iota(people.begin(), people.end(), 1);
		
		while(n > 1){
			pointer = (pointer + k) % n;
			people.erase(people.begin() + pointer);
			n--;
		}

		printf("Case %d: %d\n", caseNumber, people[0]);
		people.clear();

		++caseNumber;
		--nc;
	}

	return 0;
}
