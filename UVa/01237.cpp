#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

std::vector<std::string> split(std::string str, std::string delimiter){
	std::string s = str;
	std::vector<std::string> out;
	out.clear();

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    out.push_back(token);
	    s.erase(0, pos + delimiter.length());
	}
	out.push_back(s);
	return out;
}

int main(){
  	int t, d, q, p, h[10005], l[10005], aux = 0;
	std::string  str, m[10005];
	std::vector<std::string> splt;
	scanf("%d%*c", &t);

	while(t--){
		if(aux == -1) printf("\n");
		scanf("%d%*c", &d);

		for(int i=0; i<d; ++i){
			std::getline(std::cin, str);
			splt = split(str, " ");
			m[i] = splt[0];
			l[i] = std::stoi(splt[1]);
			h[i] = std::stoi(splt[2]);
		}

		scanf("%d", &q);
		for(int i=0; i<q; ++i){
			aux = 0;
			scanf("%d", &p);

			for(int j=0; j<d && aux < 2; ++j){
				if(l[j] <= p && h[j] >= p){
					str = m[j];
					++aux;
				}
			}

			if(aux == 1){
				std::cout << str << std::endl;
			}else{
				printf("UNDETERMINED\n");
			}
		}

		aux = -1;
	}

	return 0;
}
