#include <cstdio>
#include <map>
#include <vector>

std::map<int, int> cycles;

int next(int n){
	if(n%2==0) return n/2;
	else return 3*n+1;
}

int depth(int x){
	if(x==1) return 1;
	
	if(cycles.find(x) != cycles.end()) return cycles[x];
	
	int out = 1 + depth(next(x));
	cycles[x] = out;
	return out;
}
	

int main(){
	int i, j, level, aux, max;
	bool swyped;
	while(scanf("%d %d", &i, &j) != EOF){
		swyped = false;
		if(i > j){
			aux = i; i = j; j = aux;
			swyped = true;
		}
		max = 1;
		cycles.clear();
		cycles[1] = 1;

		for(int k=i; k<=j; ++k){
			aux = depth(k);
			max = max < aux ? aux : max;
		}

		if(swyped){ aux = i; i = j; j = aux; }
		printf("%d %d %d\n", i, j, max);
	}

	return 0;
}
