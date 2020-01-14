#include <cstdio>
#include <map>

int main(){
	int c, id, amount;
	float sum = 0;
	std::map<int, float> table = {{1001, 1.5}, {1002, 2.5}, {1003, 3.5}, {1004, 4.5}, {1005, 5.5}};
	scanf("%d", &c);

	for(int i=0; i<c; ++i){
		scanf("%d %d", &id, &amount);
		sum += table[id]*amount;
	}

	printf("%.2f\n", sum);
	return 0;
}
