#include <cstdio>
#include <iostream>
#include <set>

int main(){
	int k, m, c, r, s;
	bool yes;
	std::string course;
	std::set<std::string> selected;

	while(scanf("%d", &k) && k != 0){
		scanf("%d", &m);

		selected.clear();
		for(int i=0; i<k; i++){
			std::cin >> course;
			selected.insert(course);
		}
		
		yes = true;
		for(int i=0; i<m; i++){
			scanf("%d %d", &c, &r);
			s = 0;
			for(int j=0; j<c; j++){
				std::cin >> course;
				if(selected.count(course)) s++;
			}

			yes &= s >= r;
		}

		if(yes) printf("yes\n");
		else printf("no\n");
		
	}

	return 0;
}
