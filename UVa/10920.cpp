#include <cstdio>
#include <iostream>
#include <math.h>

int main(){
	long long sz, p, x, y, s;
	
	while(scanf("%lld %lld", &sz, &p) != EOF && sz != 0 && p != 0){
		x = ceil(sz/2.0); y = x;
		s = 1;
		
		for(int i=1; s < p && x <= sz && y <= sz; i++){

			if(s + i < p){
				s += i; y += i;
			}else{
				for(int j=0; j<i && s < p; j++){
					s += 1; y += 1;
				}
			}
			
			if(s + i < p){
				s += i; x-=i;
			}else{
				for(int j=0; j<i && s < p; j++){
					s += 1; x -= 1;
				}
			}
			
			i++;

			if(s + i < p){
				s += i; y-=i;
			}else{
				for(int j=0; j<i && s < p; j++){
					s += 1; y -= 1;
				}
			}
			
			if(s + i < p){
				s+=i; x+=i;
			}else{
				for(int j=0; j<i && s < p; j++){
					s += 1; x += 1;
				}
			}
		}

		printf("Line = %lld, column = %lld.\n", y, x);
	}

	return 0;
}
