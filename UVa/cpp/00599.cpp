#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

std::map<char, int> split(std::string str, std::string delimiter){
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

	std::map<char, int> map; map.clear();
	for(int i=0; i<out.size(); i++){
		map[out[i][0]] = i;
	}

	return map;
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
	
	int findSet(int a){
		if(vi[a] == a) return a;
		
		return vi[a] = findSet(vi[a]);
	}

	bool isSameSet(int a, int b){
		return findSet(a) == findSet(b);
	}

	void unionSet(int a, int b){
		if(isSameSet(a, b)) return;

		int pa = findSet(a);
		int pb = findSet(b);

		if(rank[pa] > rank[pb]){
			vi[pb] = pa;
		}else{
			vi[pa] = pb;
			if(rank[pa] == rank[pb]) rank[pb]++;
		}
	}
	
	void fullPathCompression(){
		for(int i=0; i<vi.size(); ++i){
			findSet(i);
		}
	}
	
	int numDisjointSets(){
		fullPathCompression();
		std::vector<int> counter(vi.size(), 0);
		int amount = 0;

		for(int i=0; i<vi.size(); ++i){
			if(counter[vi[i]] == 0){ ++amount; }
			counter[vi[i]]++;
		}

		return amount;
	}
	
	int sizeOfSet(int a){
		fullPathCompression();
		int amount = 0;

		for(int i=0; i<vi.size(); ++i){
			if(vi[i] == a) amount++;
		}

		return amount;
	}

	std::vector<int> getDisjointSetsCounter(){
		fullPathCompression();
		std::vector<int> counter(vi.size(), 0);

		for(int i=0; i<vi.size(); ++i){
			counter[vi[i]]++;
		}

		return counter;
	}

	void clear(){
		for(int i=0; i<vi.size(); ++i){ vi[i]=i; rank[i] = 0; };
	}

	void print(){
		printf("Item   |");
		for(int i=0; i<vi.size(); i++){
			for(int j=10000; j!=1; j/=10) if(i < j) printf(" ");
			printf("%d|", i);
		}
		
		printf("\nParent |");
		for(int i=0; i<vi.size(); i++){
			for(int j=10000; j!=1; j/=10) if(vi[i] < j) printf(" ");
			printf("%d|", vi[i]);
		}	
	}
};

int main(){
	int c;
	scanf("%d", &c);
	std::string line;
	std::vector<std::pair<char, char>> edges;
	std::vector<int> counter;
	int trees, acorns;
	while(c--){
		trees = 0;
		acorns = 0;
		edges.clear();
		counter.clear();

		while(std::getline(std::cin, line) && line[0] != '*'){
			edges.push_back(std::pair<char, char>(line[1], line[3]));
		}

		std::getline(std::cin, line);
		std::map<char, int> map = split(line, ",");
		union_find u(map.size());

		for(int i=0; i<edges.size(); ++i){
			u.unionSet(map[edges[i].first], map[edges[i].second]);
		}

		counter = u.getDisjointSetsCounter();
	
		for(int i=0; i<counter.size(); ++i){
			if(counter[i]>1) ++trees;
			else if(counter[i]==1) ++acorns;
		}
//		u.print();
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}

	return 0;
}
