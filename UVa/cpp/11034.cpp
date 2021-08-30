#include <cstdio>
#include <iostream>
#include <queue>

int main(){
	int c, l, m, travels, aux;
	std::string str;
	std::queue<int> left, right;
	bool onLeft;
	scanf("%d", &c);

	while(c--){
		scanf("%d %d", &l, &m);
		l*= 100;
		onLeft = true;
		travels = 0;
		for(int i=0; i<m; ++i){
			std::cin >> aux >> str;
			if(str.compare("left") == 0){
				left.push(aux);
			}else{
				right.push(aux);
			}
		}

		while(left.size() > 0 || right.size() > 0){
			aux = 0;
			if(onLeft && left.size() > 0){
				while(aux < l && left.size() > 0){
					if(aux+left.front() > l) break;
					
					aux += left.front();
					left.pop();
				}
				++travels;
				onLeft = false;
			}else if(onLeft && right.size() > 0){
				++travels;
				onLeft = false;
			}
			
			aux = 0;
			if(!onLeft && right.size() > 0){
				while(aux < l && right.size() > 0){
					if(aux+right.front() > l) break;
					
					aux += right.front();
					right.pop();
				}

				++travels;
				onLeft = true;
			}else if(!onLeft && left.size() > 0){
				++travels;
				onLeft = true;
			}
		}

		printf("%d\n", travels);
	}

	return 0;
}
