#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int f, r, fs[15], rs[15], m, n, d;
	double max, curr;
	std::vector<double> ds;

	while(scanf("%d", &f) != EOF && f > 0){
		ds.clear();	
		scanf("%d", &r);

		for(int i=0; i<f; ++i){
			scanf("%d", &fs[i]);
		}
		
		for(int i=0; i<r; ++i){
			scanf("%d", &rs[i]);
		}

		for(int i=0; i<f; ++i){
			m = fs[i];
			for(int j=0; j<r; ++j){
				n = rs[j];
				ds.push_back(((double)n)/((double)m));
			}
		}
		
		std::sort(ds.begin(), ds.end(), std::greater<double>());
		max = -9999999;
		for(int i=0; i<ds.size()-1; ++i){
			curr = ds[i]/ds[i+1];
			if(curr > max) max = curr;
		}

		printf("%.2lf\n", max);
	}

	return 0;
}
