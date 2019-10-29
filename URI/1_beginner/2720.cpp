#include <cstdio>
#include <algorithm>
#include <vector>

struct present{
	int id;
	int size;
	int index;
};

bool compareBySize(const present &a, const present &b){
	if(a.size == b.size){
		return a.id < b.id;
	}
	return a.size > b.size;
}

int main(){
	int t, n, k, id, h, w, l;
	std::vector<present> presents;
	std::vector<int> chosenIds;
		
	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &k);
		presents.clear();
		chosenIds.clear();

		for(int i=0; i<n; i++){
			scanf("%d %d %d %d", &id, &h, &w, &l);
			present bob = { .id = id, .size = h*w*l, .index = i };
			//printf("Adding struct id: %d size: %d index: %d\n", id, h*w*l, i);
			presents.push_back(bob);
		}

		std::sort(presents.begin(), presents.end(), compareBySize);

		for(int i=0; i<k; i++){
			chosenIds.push_back(presents[i].id);
		}

		std::sort(chosenIds.begin(), chosenIds.end());
		for(int i=0; i<k; i++){
			printf("%d", chosenIds[i]);
			if(i+1 < k) printf(" ");
		}

		printf("\n");
	}

	return 0;
}
