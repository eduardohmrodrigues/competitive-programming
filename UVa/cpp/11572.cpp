#include <cstdio>
#include <map>

int main(){
	std::map<int, int> map;
	int c, n, max, aux, totalRemoved, counter;
	scanf("%d", &c);
	
	while(c--){
		scanf("%d", &n);
		max = 0;
		totalRemoved = 0;
		counter = 0;
		map.clear();

		for(int i=0; i<n; ++i){
			scanf("%d", &aux);
			if(map.find(aux) == map.end() || map[aux] < totalRemoved){
				map[aux] = i;
				counter++;
				max = max < counter ? counter : max;
			}else{
				counter = counter - ((map[aux]+1) - totalRemoved);
				totalRemoved = map[aux]+1;
				map[aux] = i;
				counter++;
			}
		}

		printf("%d\n", max);
	}

	return 0;
}
