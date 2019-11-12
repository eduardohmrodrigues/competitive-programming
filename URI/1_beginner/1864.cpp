#include <cstdio>
#include <string>

int main(){
	std::string str = "LIFE IS NOT A PROBLEM TO BE SOLVED";
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}
