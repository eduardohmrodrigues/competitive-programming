#include <iostream>
#include <cstdio>

int main(){
	long long balance = 0;

	int n, c;
	char t;
	scanf("%d%*c", &n);

	while(n > 0){
		scanf("%c %d%*c", &t, &c);
		
		if(t == 'G'){
			balance -= c;
		}else{
			balance += c;
		}

		n--;
	}
	
	if(balance < 0){
		printf("NAO VAI TER CORTE, VAI TER LUTA!\n");
	}else{
		printf("A greve vai parar.\n");
	}

	return 0;
}

