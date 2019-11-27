#include <cstdio>
#include <iostream>
#include <vector>

int main(){
	int x, y, r, aux;
	std::string str;
	std::vector<int> temp, temp2;
	std::vector<std::vector<int>> mat;
	
	while(scanf("%d %d", &x, &y) != EOF){
		mat.assign(x, std::vector<int>(y, 0));
		temp.clear(); temp2.clear();

		for(int i=0; i<x; ++i){
			scanf("%d", &r);

			for(int j=0; j<r; ++j){
				scanf("%d", &aux);
				temp.push_back(aux-1);	
			}
			
			if(r == 0) std::getline(std::cin, str);

			while(temp.size() > 0){
				scanf("%d", &aux);
				mat[i][temp[0]] = aux;
				temp.erase(temp.begin());
			}
		}
		
		printf("%d %d\n", y, x);
		for(int j=0; j<y; ++j){
			temp.clear(); temp2.clear();

			for(int i=0; i<x; ++i){
				if(mat[i][j] != 0) {
					temp.push_back(i);
					temp2.push_back(mat[i][j]);
				}
			}
			
			printf("%ld", temp.size());
			for(int i=0; i<temp.size(); ++i){
				printf(" %d", temp[i]+1);
			}
			printf("\n");
			for(int i=0; i<temp2.size(); ++i){
				if(i>0) printf(" ");
				printf("%d", temp2[i]);
			}
			printf("\n");
		}
	}

	return 0;
}
