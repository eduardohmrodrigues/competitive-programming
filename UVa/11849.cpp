#include <cstdio>
#include <set>

int main(){
	long long n, m, total, aux;
	std::set<int> set;

	while(scanf("%lld %lld", &n, &m) != EOF && (n != 0 || m != 0)){
		total = 0;
		set.clear();

		for(int i=0; i<n+m; i++){
			scanf("%lld", &aux);

			if(set.find(aux) != set.end()){
				total++;
			}else{
				set.insert(aux);
			}
		}
		
		printf("%lld\n", total);
	}

	return 0;
}
