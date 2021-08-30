#include <cstdio>
#include <iostream>
#include <algorithm>


const int DIM = 1025;

int main(){
	int t, d, n, x, y, s, maxPopulation, maxX, maxY;
	int grid[DIM*DIM];
	std::string str;

	for(int i=0; i<DIM; ++i){
		for(int j=0; j<DIM; ++j){
			grid[i*DIM + j] = 0;
		}
	}

	scanf("%d", &t);
	while(t--){
		maxPopulation = 0; maxX = 0; maxY = 0;
		scanf("%d", &d);
		scanf("%d", &n);
		
		int startX, startY, endX, endY;
		while(n--){
			scanf("%d %d %d", &x, &y, &s);

			startX = std::max(x-d, 0); startY = std::max(y-d, 0);
			endX = std::min(x+d, DIM-1); endY = std::min(y+d, DIM-1);
			for(int i=startX; i<=endX; ++i){
				for(int j=startY; j<=endY; ++j){
					grid[i*DIM+j] += s;
				}
			}
		}
		
		for(int i=0; i<DIM; ++i){
			for(int j=0; j<DIM; ++j){
				n = grid[i*DIM + j];
				
				if(n > maxPopulation){
					maxPopulation = n;
					maxX = i;
					maxY = j;
				}

				grid[i*DIM + j] = 0;
			}
		}
		
		printf("%d %d %d\n", maxX, maxY, maxPopulation);
		std::getline(std::cin, str);
	}

	return 0;
}
