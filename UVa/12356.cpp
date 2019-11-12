#include <cstdio>
#include <iostream>
#include <string>

int main(){
	int ls[100001], rs[100001];
	int s, b, l, r;
	std::string ml, mr;
	while(scanf("%d %d", &s, &b) != EOF && (s != 0 || b != 0)){
		for(int i=1; i<=s; i++) {
			ls[i] = i-1;
			rs[i] = i+1;
		}

		while(b--){
			scanf("%d %d", &l, &r);
		
			mr = rs[r] > s ? "*" : std::to_string(rs[r]);
			ml = ls[l] < 1 ? "*" : std::to_string(ls[l]);
			ls[rs[r]] = ls[l];
			rs[ls[l]] = rs[r];
			std::cout << ml << " " << mr << std::endl;
		}

		printf("-\n");
	}

	return 0;
}
