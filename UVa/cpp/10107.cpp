#include <cstdio>
//#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	long long x, a, b;
	std::vector<long long> vec;
	vec.clear();
	while(scanf("%lld", &x) != EOF){
		vec.push_back(x);
		if(vec.size()%2 != 0) {
			std::nth_element(vec.begin(), vec.begin()+vec.size()/2, vec.end());
			a = vec[vec.size()/2];
			printf("%lld\n", a);
		}
		else{
			std::nth_element(vec.begin(), vec.begin()+(vec.size()/2)-1, vec.end());
			a = vec[vec.size()/2-1]; 
			std::nth_element(vec.begin(), vec.begin()+vec.size()/2, vec.end());
			b = vec[vec.size()/2]; 
			
			printf("%lld\n", (a+b)/2);
		}
	}
	
	return 0;
}
