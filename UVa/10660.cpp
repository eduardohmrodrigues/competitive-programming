#include <cstdio>
#include <cmath>

void clear(long long arr[25]){
	for(int i=0; i<25; ++i) arr[i] = 0;
}

void print(int arr[25]){
	for(int i=0; i<25; ++i) printf("%d ", arr[i]);
	printf("\n");
}

int getDist(int a, int b){
	int x1 = a/5;
	int y1 = a%5;

	int x2 = b/5;
	int y2 = b%5;
	
	return std::abs(x1-x2) + std::abs(y1-y2);
}

int getMinDist(int p, int a, int b, int c, int d, int e){
	int dist = getDist(p, a);

	int aux = getDist(p, b);
	dist = dist < aux ? dist : aux;

	aux = getDist(p, c);
	dist = dist < aux ? dist : aux;

	aux = getDist(p, d);
	dist = dist < aux ? dist : aux;

	aux = getDist(p, e);
	dist = dist < aux ? dist : aux;

	return dist;
}

int main(){
	long long city[25], minDist, sum, t, p, x, y, s, aux;
	int pops[25], minDists[5];
	scanf("%lld", &t);

	while(t--){
		clear(city);
		scanf("%lld", &p);

		for(int i=0; i<p; ++i){
			scanf("%lld %lld %lld", &x, &y, &s);
			city[x*5+y] = s;
			pops[i] = x*5+y;
		}
		
		minDists[0] = 0; minDists[1] = 1; minDists[2] = 2;
		minDists[3] = 3; minDists[4] = 4;
		minDist = 9223372036854775805;

		for(int a=0; a<25; ++a){
		for(int b=a+1; b<25; ++b){
		for(int c=b+1; c<25; ++c){
		for(int d=c+1; d<25; ++d){
		for(int e=d+1; e<25; ++e){
			sum = 0;
			for(int f=0; f<p; ++f){
				sum += getMinDist(pops[f], a, b, c, d, e)*city[pops[f]];
			}

			if(sum < minDist){
				minDist = sum;
				minDists[0] = a; minDists[1] = b; minDists[2] = c;
				minDists[3] = d; minDists[4] = e;
			}
		}
		}
		}
		}
		}

		printf("%d %d %d %d %d\n", minDists[0], minDists[1], minDists[2], minDists[3], minDists[4]);
	}

	return 0;
}
