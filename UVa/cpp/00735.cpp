#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <utility>

int main(){
	int s, m, com, per;
	std::map<int, std::pair<int, int>> map;
	std::set<int> possiblePoints;

	possiblePoints.insert(0); possiblePoints.insert(50);
	for(int i=1; i<21; ++i) {
		possiblePoints.insert(i);
		possiblePoints.insert(i*2);
		possiblePoints.insert(i*3);
	}

	std::vector<int> points(possiblePoints.begin(), possiblePoints.end());

	for(int a=0; a<points.size(); ++a){
		for(int b=a; b<points.size(); ++b){
			for(int c=b; c<points.size(); ++c){
				s = points[a]+points[b]+points[c];
				if(map.find(s) == map.end()) map[s] = std::pair<int, int>(0, 0);
				++map[s].first;

				if(a == b && b == c) ++map[s].second;
				else if(a == b || b == c) map[s].second += 3;
				else map[s].second += 6;
			}
		}
	}


	while(scanf("%d", &s) != EOF && s > 0){
		if(map.find(s) != map.end()){
			 printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", s, map[s].first);
			 printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", s, map[s].second);
		}
		else{
			 printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", s);
		}

		printf("**********************************************************************\n");
	}

	printf("END OF OUTPUT\n");
	return 0;
}
