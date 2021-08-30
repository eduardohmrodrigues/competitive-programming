#include <cstdio>
#include <unordered_map>
#include <math.h>
#include <algorithm>

int main(){
	int n, a;
	long long max, aux;
	std::unordered_map<int, long long> map;
	std::unordered_map<int, long long> mapot;

	while(scanf("%d", &n) != EOF){
		map.clear();
		max = 0;

		a = pow(2, n);
		for(int i=0; i<a; i++){
			map[i] = 0;
			mapot[i] = 0;
			scanf("%lld", &map[i]);
		}

		for(int i=0; i<a; i++){
			for(int j=0; j<n; j++){
				aux = i^(1UL<<j);
				mapot[i] += map[aux];
			}
		}
		
		for(int i=0; i<a; i++){
			aux = 0;
			
			for(int j=0; j<n; j++){
				aux = i^(1UL<<j);
				if(mapot[i] + mapot[aux] > max){
					max = mapot[i] + mapot[aux];
				}
			}
		}

		printf("%lld\n", max);
	}

	return 0;
}
