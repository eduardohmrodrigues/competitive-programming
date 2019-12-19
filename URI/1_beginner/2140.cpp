#include <cstdio>

int main(){
	int x, y, e, aux;
	int c[6] = {2, 5, 10, 20, 50, 100};
	bool found;
	
	while(scanf("%d %d", &x, &y) != EOF && x != 0 || y != 0){
		e = y-x;
		x = 0; y = 5;
		found = false;

		while(!found){
			aux = c[x] + c[y];

			if(aux == e) found = true;
			else if(aux < e) ++x;
			else --y;

			if(x > y) break;
		}

		if(found) printf("possible\n");
		else printf("impossible\n");
	}

	return 0;
}
