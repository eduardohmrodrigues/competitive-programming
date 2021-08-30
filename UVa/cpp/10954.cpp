#include <cstdio>
#include <queue>

int main(){
	std::priority_queue<long long> q;
	long long n, aux, temp, sum, costSum;

	while(scanf("%lld", &n) != EOF && n>0){
		sum = 0;
		costSum = 0;

		while(n--){
			scanf("%lld", &aux);
			q.push(-aux);		
		}
		

		while(q.size() > 1){
			aux = -q.top(); q.pop();
			temp = -q.top(); q.pop();
			aux = aux+temp;
			costSum += aux;
			q.push(-aux);
		}
		
		q.pop();
		printf("%lld\n", costSum);
	}

	return 0;
}
