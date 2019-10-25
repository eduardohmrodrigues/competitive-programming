#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>

void printvector(std::vector<int> vec){
	printf("{");
	for(int i=0; i<vec.size(); i++){
		printf(" %d ", vec[i]);
	}
	printf("}\n");
}

int main(){
	int n, pointer, m;	
	
	std::cin >> n;	
	while(n != 0){
		m = 1;
		pointer = -m;

		std::vector<int> blocks(n);
		std::vector<int> blocksTemp(n);
		std::iota(blocks.begin(), blocks.end(), 1);
		std::iota(blocksTemp.begin(), blocksTemp.end(), 1);
//		printvector(blocksTemp);
		while(n > 1){
			pointer = (pointer + m) % n;
			if(blocksTemp[pointer] == 13){
//				printf("Deu merda, removi o 13 com ainda %d elementos. Reset.\n", n);
				m++;
				pointer = -m;
				n = blocks.size();
				blocksTemp.clear();
				blocksTemp.resize(n, 0);
				std::iota(blocksTemp.begin(), blocksTemp.end(), 1);
//				printvector(blocksTemp);
			}else{
//				printf("m = %d pointer = %d e vou remover o %d\n", m, pointer, blocksTemp[pointer]);
				blocksTemp.erase(blocksTemp.begin() + pointer);
//				printvector(blocksTemp);
				pointer--;
				n--;
			}
		}

		printf("%d\n", m);
		std::cin >> n;
	}

	return 0;
}

