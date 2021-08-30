#include <cstdio>
#include <bitset>

int abs(int x){
	return x > 0 ? x : -x;
}

int main(){
	int n, x, y, d, t;
	std::bitset<3001> bs;
	bool flag;

	while(scanf("%d", &n) != EOF){
		t = n;
		flag = true;
		bs.reset();

		t--;
		scanf("%d", &x);
		while(t--){
			scanf("%d", &y);
			d = abs(x-y);
			x = y;	
		
			if(d>0 && d<3001) bs.set(d);
		}
		
		for(int i=1; i<n && flag; i++) flag &= bs[i];

		if(flag) printf("Jolly\n");
		else printf("Not jolly\n");
	}

	return 0;
}
