#include <cstdio>
#include <vector>

int main(){
	int n;
	std::vector<int> fib;
	fib.push_back(0);
	fib.push_back(1);
	scanf("%d", &n);
	
	for(int i=0; i < 2 && i < n; i++){
		if(i>0) printf(" ");
		printf("%d", fib[i]);
	}

	for(int i=2; i<n; i++){
		printf(" ");
		fib.push_back(fib[i-2] + fib[i-1]);
		printf("%d", fib[i]);
	}

	if(n>0) printf("\n");
	return 0;
}
