#include <cstdio>
#include <math.h>
#include <iostream>

int main(){
	int x, pages, page;

	while(scanf("%d", &x) && x != 0){
		pages = std::ceil(((double)x)/4.0);
		page = 1;
		
		printf("Printing order for %d pages:\n", x);
		for(int i=pages*4, j=1; i>pages*2; --i){
			std::cout << "Sheet " << page << ", front: ";
			if(i > x) std::cout << "Blank";
			else std::cout << i;
			std::cout << ", " << j++ << std::endl;
			
			if(j>x) break;
			--i;

			std::cout << "Sheet " << page << ", back : " << j++ << ", ";
			if(i>x) std::cout << "Blank";
			else std::cout << i;
			std::cout << std::endl;

			page++;
		}
	}

	return 0;
}
