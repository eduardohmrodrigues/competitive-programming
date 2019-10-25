#include <iostream>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <limits>

#define INF std::numeric_limits<int>::max()
//                      5            4       3 4 4 4 4 4 5
int calculateAmount(int nplanks, int w, std::vector<int> p){
	int pointer1 = 0, pointer2 = p.size()-1;
	int pamount = 0;
	int counter = 0;
	
//	std::cout << "nPlanks = " << nplanks << " | width = " << w << std::endl;
		
	if(p[0] > w){
		return INF;
	}

	for(int i=0; i<nplanks; i++){
		bool found = false;
		if(pointer1 > pointer2){
			return INF;
		}

		do{
			int sum = p[pointer2] + p[pointer1];

			if(p[pointer2] == w){
//				std::cout << "Accepted plank size " << p[pointer2] << std::endl;
				--pointer2;
				++pamount;
				found = true;
			}else if(p[pointer1] == w){
//				std::cout << "Accepted plank size " << p[pointer2] << std::endl;
				++pointer1;
				++pamount;
				found = true;
			}else if(p[pointer2] > w){
				pointer2--;
			}else if(pointer1 == pointer2){
				return INF;
			}else if(sum == w){
//				std::cout << "Accepted plank size p1 = " << p[pointer1] << " p2 = "  << p[pointer2] << " sum = " << sum << std::endl;
				--pointer2;
				++pointer1;
				pamount += 2;
				found = true;	
			}else if(sum > w){
				--pointer2;
			}else{
				++pointer1;
			}
		}while(!found && pointer1 < pointer2);
		
//		std::cout << i << " < " << nplanks << " found = " << found << " p1 = " << pointer1 << " p2 = " << pointer2 << std::endl;
		if(!found){
			return INF;
		}
	}
	

	return pamount;
}

int main(){
	float n, m, l;
	int  k, s;

	std::vector<int> planks;
	
	while(scanf("%f %f", &n, &m) && n && m){
		scanf("%f", &l);
		scanf("%d", &k);
		
		planks.clear();

//		printf("n = %f m = %f l = %f k = %d\n", n, m, l, k);
		for(int i=0; i<k; i++){
			scanf("%d", &s);
			planks.push_back(s);
		}
		
		std::sort(planks.begin(), planks.end());
		
		int nPlanks = (n*100)/l;
		int mPlanks = (m*100)/l;
		
//		printf("nPlanks = %d\n", nPlanks);
//		printf("mPlanks = %d\n", mPlanks);
		if(nPlanks > k && mPlanks > k){
			printf("impossivel\n");
			continue;
		}
		
		//N oriented calculation
		int nAmount = INF;
		if(nPlanks > 0 && (nPlanks*l)/100 == n){
			nAmount = calculateAmount(nPlanks, m, planks);
		}

		//M oriented calculation
		int mAmount = INF;
		if(m != n && mPlanks > 0 && (mPlanks*l)/100 == m){
			mAmount = calculateAmount(mPlanks, n, planks);
		}

		if(nAmount == INF && mAmount == INF){
			printf("impossivel\n");
		}else if(nAmount < mAmount){
			printf("%d\n", nAmount);
		}else{
			printf("%d\n", mAmount);
		}
	}

	return 0;
}
