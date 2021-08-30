#include <cstdio>

int main(){
	int n, a, b, c;
	bool found;
	scanf("%d", &n);

	while(n--){
		found = false;
		scanf("%d %d %d", &a, &b, &c);

		for(int x=-100; x<101 && !found; ++x){
			for(int y=-100; y<101 && !found; ++y){
				if(x == y) continue;
				for(int z=-100; z<101 && !found; ++z){
					if(y == z || x == z) continue;
					if(x+y+z == a && x*y*z == b && (x*x + y*y + z*z) == c){
						found = true;
						printf("%d %d %d\n", x, y, z);
					}
				}
			}
		}

		if(!found) printf("No solution.\n");
	}

    return 0;
}
