#include <cstdio>
#include <iostream>

int main(){
	unsigned long n, a, b;
	bool toggle;
	while(scanf("%lu", &n) != EOF && n != 0){
		a = 0;
		b = 0;
		toggle = false;
		for(int i=0; i<32; i++){
			if((n & 1UL<<i)>0){
				if(!toggle){
					a |= 1UL << i;
				}else{
					b |= 1UL << i;
				}

				toggle = !toggle;
			}
		}
		
		std::cout << a << " " << b << std::endl;
	}

	return 0;
}
