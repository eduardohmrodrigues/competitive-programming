#include <cstdio>
#include <cmath>

int main(){
	int n, m, q, ns[1005], c = 1, sum;
	unsigned int diff, cdiff;

	while(scanf("%d", &n) != EOF && n > 0){
		printf("Case %d:\n", c);
		++c;

		for(int i=0; i<n; ++i){
			scanf("%d", &ns[i]);
		}
		
		scanf("%d", &m);
		while(m--){
			diff = 4294967295;
			scanf("%d", &q);
			
			for(int i=0; i<n-1; ++i){
				for(int j=i+1; j<n; ++j){
					cdiff = std::abs((ns[i] + ns[j]) - q);
					if(cdiff < diff){
						 diff = cdiff;
						 sum = ns[i] + ns[j];
					}
				}
			}

			printf("Closest sum to %d is %d.\n", q, sum);
		}
	}

	return 0;
}
