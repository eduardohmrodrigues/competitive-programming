#include <cstdio>
#include <set>
#include <vector>

int main(){
	std::multiset<int, std::greater<int>> green;
	std::multiset<int, std::greater<int>> blue;
	
	bool first = true;
	int n, b, sg, sb, aux;
	std::vector<int> beg, beb;
	scanf("%d", &n);

	while(n--){
		if(!first) printf("\n");
		first = false;
	
		green.clear();
		blue.clear();
		scanf("%d %d %d", &b, &sg, &sb);

		for(int i=0; i<sg; ++i){
			scanf("%d", &aux);
			green.insert(aux);
		}
		
		for(int i=0; i<sb; ++i){
			scanf("%d", &aux);
			blue.insert(aux);
		}

		while(blue.size() > 0 && green.size() > 0){
			aux = 0;
			while(aux<b && green.size() > 0 && blue.size() > 0){
				sg = (*green.begin());
				sb = (*blue.begin());
				green.erase(green.begin());
				blue.erase(blue.begin());
				

				if(sg > sb){
					beg.push_back(sg-sb);
				}else if(sb > sg){
					beb.push_back(sb-sg);
				}

				++aux;
			}

			while(beg.size()>0 || beb.size()>0){
				if(beg.size()>0){
					green.insert(beg[0]);
					beg.erase(beg.begin());
				}

				if(beb.size()>0){
					blue.insert(beb[0]);
					beb.erase(beb.begin());
				}
			}
		}

		if(blue.size() > 0){
			printf("blue wins\n");
			for(std::multiset<int>::iterator it=blue.begin(); it!=blue.end(); ++it){
				printf("%d\n", (*it));
			}
		}else if(green.size() > 0){
			printf("green wins\n");
			for(std::multiset<int>::iterator it=green.begin(); it!=green.end(); ++it){
				printf("%d\n", (*it));
			}
		}else{
			printf("green and blue died\n");
		}
	}

	return 0;
}
