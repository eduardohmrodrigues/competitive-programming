#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int main(){
	std::vector<std::string> big, small;
	int N, n, a, b, c, d;
	bool match;
	
	while(scanf("%d %d%*c", &N, &n) != EOF && N != 0 && n != 0){
		big.clear(); small.clear();
		big = std::vector<std::string>(N); small = std::vector<std::string>(n);
		a = 0; b = 0; c = 0; d = 0;

		for(int i=0; i<N; i++) {
			std::getline(std::cin, big[i]);
		}
		for(int i=0; i<n; i++){
			 std::getline(std::cin, small[i]);
		}
		
		for(int i=0; i<=N-n; i++){
			for(int j=0; j<=N-n; j++){
				match = true;
				for(int k=0; k<n && match; ++k)
				for(int l=0; l<n && match; ++l){
					match &= big[i+k][j+l] == small[k][l];
				}
				if(match) a += 1;


				match = true;
				for(int k=0; k<n && match; ++k)
				for(int l=n-1; l>=0 && match; --l){
					match &= big[i+k][j+((n-l)-1)] == small[l][k];
				}
				if(match) b += 1;


				match = true;
				for(int k=n-1; k>=0 && match; --k)
				for(int l=n-1; l>=0 && match; --l){
					match &= big[i+((n-k)-1)][j+((n-l)-1)] == small[k][l];
				}
				if(match) c += 1;


				match = true;
				for(int k=n-1; k>=0 && match; --k)
				for(int l=0; l<n && match; ++l){
					match &= big[i+((n-k)-1)][j+l] == small[l][k];
				}
				if(match) d += 1;
			}
		}

		printf("%d %d %d %d\n", a, b, c, d);
	}

	return 0;
}
