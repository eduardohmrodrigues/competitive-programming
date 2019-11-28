#include <cstdio>
#include <iostream>
#include <vector>

void split(std::string str, std::string delimiter, std::vector<std::string> *out){
	std::string s = str;
	out->clear();

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    out->push_back(token);
	    s.erase(0, pos + delimiter.length());
	}
	out->push_back(s);
}

class union_find{
private:
	std::vector<int> vi;
	std::vector<int> rank;

public:
	union_find(int n){
		vi.assign(n, 0);
		rank.assign(n, 0);

		for(int i=0; i<n; ++i){ vi[i]=i; };
	}
	
	~union_find(){
		vi.clear();
		rank.clear();
	}
	
	int find_set(int a){
		if(vi[a] == a) return a;
		
		return vi[a] = find_set(vi[a]);
	}

	bool is_same_set(int a, int b){
		return find_set(a) == find_set(b);
	}

	void union_set(int a, int b){
		if(is_same_set(a, b)) return;

		int pa = find_set(a);
		int pb = find_set(b);

		if(rank[pa] > rank[pb]){
			vi[pb] = pa;
		}else{
			vi[pa] = pb;
			if(rank[pa] == rank[pb]) rank[pb]++;
		}
	}
};

int main(){
	int c, n, ci, cj, success, fail;
	std::vector<std::string> temp;
	std::string str;
	std::cin >> c;
	std::getline(std::cin, str);
	
	while(c--){
		success = 0; fail = 0;
		scanf("%d%*c", &n);
		union_find u(n);
		
		while(std::getline(std::cin, str) && !str.empty()){
			temp.clear();
			split(str, " ", &temp);
			str = temp[0]; ci = std::stoi(temp[1]); cj = std::stoi(temp[2]);
			
			if(str[0] == 'c'){
				u.union_set(ci-1, cj-1);
			}else{
				if(u.is_same_set(ci-1, cj-1)){
					++success;
				}else{
					++fail;
				}
			}
		}

		printf("%d,%d\n", success, fail);
		if(c>0) printf("\n");
	}
	
	return 0;
}
