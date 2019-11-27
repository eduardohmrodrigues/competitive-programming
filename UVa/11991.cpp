#include <cstdio>
#include <map>
#include <vector>

int main(){
	int n, m, k, aux;
	std::map<int, std::vector<int>> mat;

	while(scanf("%d %d", &n, &m) != EOF){
		mat.clear();
		for(int i=1; i<=n; ++i){
			scanf("%d", &aux);
			if(mat.find(aux) == mat.end()) mat[aux] = std::vector<int>();
			mat[aux].push_back(i);
		}
		
		for(int i=0; i<m; ++i){
			scanf("%d %d", &k, &aux);
			if(mat.find(aux) == mat.end() || mat[aux].size() < k) printf("0\n");
			else printf("%d\n", mat[aux][k-1]);
		}
	}

	return 0;
}
