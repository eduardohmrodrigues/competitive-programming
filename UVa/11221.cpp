#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>

#define vc std::vector<char>
#define vvc std::vector<vc>

void clear(vvc *vec){
	for(int i=0; i<vec->size(); i++) (*vec)[i].clear();
	vec->clear();
}

void fillMagic(vvc *vec, std::string str, int d){
	for(int i=0; i<str.length(); i++){
		(*vec)[i/d][i%d] = str[i];
	}
}

bool isMagic(vvc vec){
	bool magic = true;
	std::string s1, s2, s3, s4;

	for(int i=0; i<vec.size()/2 && magic; i++){
		s1 = ""; s2 = ""; s3 = ""; s4 = "";
		for(int j=i; j<vec[i].size() && magic; j++){
			s1 += vec[i][j];
			s2 += vec[j][i];
			s3 += vec[vec.size()-(i+1)][vec.size()-(j+1)];
			s4 += vec[vec.size()-(j+1)][vec.size()-(i+1)];
		}
		
		magic &= (s1.compare(s2) == 0) && (s2.compare(s3) == 0) && (s3.compare(s4) == 0);
	}

	return magic;
}

int main(){
	int n, ind = 1;
	int sqr;
	vvc magic;
	scanf("%d%*c", &n);
	std::string str;
	while(n--){
		clear(&magic);

		std::getline(std::cin, str);
		for(int i=0; i<str.length(); ++i){
			if(str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122){
				str.erase(i, 1);
				--i;
			}
		}
		
		sqr = sqrt(str.length());
		if(sqr*sqr != str.length()){
			printf("Case #%d:\nNo magic :(\n", ind++);
			continue;
		}
		
		magic = vvc(sqr, vc(sqr, 0));
		fillMagic(&magic, str, sqr);
		
		if(isMagic(magic)) printf("Case #%d:\n%d\n", ind++, sqr);
		else printf("Case #%d:\nNo magic :(\n", ind++);
	}

	return 0;
}

