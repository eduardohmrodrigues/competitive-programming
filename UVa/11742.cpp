#include <cstdio>
#include <algorithm>
#include <utility>

int main(){
	int n, m, a, b, c, aux, ia, ib, solutions;
	bool solve;
	std::pair<int, std::pair<int, int>> constraints[25];

	while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)){
		int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};
		for(int i=0; i<m; i++){
			scanf("%d %d %d", &a, &b, &c);

			constraints[i].first = a;
			constraints[i].second.first = b;
			constraints[i].second.second = c;
		}

		solutions = 0;
		do{
			solve = true;
			for(int i=0; i<m && solve; i++){
				a = constraints[i].first;
				b = constraints[i].second.first;
				c = constraints[i].second.second;

				for(int j=0; j<n; j++){
					if(p[j] == a) ia = j;
					if(p[j] == b) ib = j;
				}

				if(ia > ib) { aux = ia; ia = ib; ib = aux; }

				if(c < 0){
					solve &= (ib - ia) >= -c;
				}else{
					solve &= (ib - ia) <= c;
				}
			}

			if(solve){
				++solutions;
			}
		}while(std::next_permutation(p, p+n));
		
		printf("%d\n", solutions);
	}	
	return 0;
}
