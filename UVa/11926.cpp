#include <cstdio>
#include <bitset>

bool fillCalendar(std::bitset<1000000> *bitset, int x, int y, int z){
	int s, e;
	bool conflict = false;

	for(int j=0; j<1000000 && x+j<1000000; j+=z){
		s = x + j; 
		e = y + j;

		for(int k=s; k<e && k<1000000 && !conflict; ++k){
			conflict = (*bitset)[k];
			bitset->set(k);
		}
	}
	
	return conflict;
}

int main(){
	std::bitset<1000000> bitset;
	int n, m, x, y, z;
	bool conflict;

	while(scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0)){
		conflict = false;
		bitset.reset();
		for(int i=0; i<n; ++i){
			scanf("%d %d", &x, &y);
			if(!conflict) conflict = fillCalendar(&bitset, x, y, 1000000);
		}

		for(int i=0; i<m; ++i){
			scanf("%d %d %d", &x, &y, &z);
			if(!conflict) conflict = fillCalendar(&bitset, x, y, z);
		}

		if(conflict) printf("CONFLICT\n");
		else printf("NO CONFLICT\n");
	}

	return 0;
}
