#include <cstdio>
#include <set>

int main(){
	long long n, k, amount, aux;
	std::multiset<int, std::greater<int>> set;
	std::multiset<int, std::greater<int>>::iterator temp;

	while(scanf("%lld", &n) != EOF && n > 0){
		set.clear();
		amount = 0;

		while(n--){
			scanf("%lld", &k);
			for(int i=0; i<k; ++i){
				scanf("%lld", &aux);
				set.insert(aux);
			}
			temp = set.end();
			temp--;
			amount += (*set.begin()) - (*temp);
			set.erase(set.begin());
			set.erase(temp);
		}

		printf("%lld\n", amount);
	}

	return 0;
}
