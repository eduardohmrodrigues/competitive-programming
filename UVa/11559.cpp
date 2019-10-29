#include <cstdio>

int main(){
	int n, b, h, w;
	int hotels[20];
	int beds[20*14];
	int minBudget = 600000;
	while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
		minBudget = 600000;
		for(int i=0; i<h; i++){
			scanf("%d", &hotels[i]);
			for(int j=0; j<w; j++){
				int bedIndex = 13*i + w;
				scanf("%d", &beds[bedIndex]);
				if(beds[bedIndex] >= n && n*hotels[i] < minBudget){
					minBudget = n*hotels[i];
				}
			}
		}

		 if(minBudget <= b){
			printf("%d\n", minBudget);
		 }else{
			printf("stay home\n");
		 }
	}
	return 0;
}
