#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

int main(){
	int M, n, aux, temp;
	std::string str;
	std::vector<std::pair<int, int>> ones, threes;

	while(scanf("%d", &M) != EOF){
		ones.clear(); threes.clear();

		for(int i=0; i<M; ++i){
			std::cin >> str;
			for(int j=0; j<M; ++j){
				aux = str[j]-'0';
				if(aux == 1) ones.push_back(std::pair<int, int>(i,j));
				else if(aux == 3) threes.push_back(std::pair<int, int>(i,j));

			}
		}

		n = -1;
		for(int i=0; i<ones.size(); ++i){
			temp = M+M+1;
			for(int j=0; j<threes.size(); ++j){
				aux = std::abs(ones[i].first - threes[j].first) + std::abs(ones[i].second - threes[j].second);
				if(aux < temp) temp = aux;
			}
			if(temp > n) n = temp;
		}

		printf("%d\n", n);
	}

	return 0;
}
