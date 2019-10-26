#include <cstdio>

int main(){
	int s[3];
	int t, x, c = 1;
	scanf("%d", &t);

	while(t>0){
		scanf("%d %d %d", &s[0], &s[1], &s[2]);

		if(s[0] > s[1]){
			x = s[0];
			s[0] = s[1];
			s[1] = x;
		}

		if(s[0] > s[2]){
			x = s[0];
			s[0] = s[2];
			s[2] = x;
		}

		if(s[1] > s[2]){
			x = s[1];
			s[1] = s[2];
			s[2] = x;
		}
		
		printf("Case %d: %d\n", c, s[1]);

		++c;
		--t;
	}

	return 0;
}
