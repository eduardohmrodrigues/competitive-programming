#include <cstdio>
#include <algorithm>
#include <math.h>
#include <iostream>

int main(){
	char cp;
	int m, n, c;
	scanf("%d", &c);

	while(c--){
		std::cin >> cp >> m >> n;
	
//		printf("Read: cp %c, m %d, n %d\n", cp, m, n);		
		if(cp == 'k'){
			printf("%d\n", ((int)ceil(m*n/2.0)));
		}else if(cp == 'K'){
			printf("%d\n", ((int)ceil(m/2.0))*((int)ceil(n/2.0)));
		}else if(cp == 'Q'){
			printf("%d\n", std::min(m, n));
		}else{
			printf("%d\n", std::min(m, n));
		}
	}

	return 0;
}
