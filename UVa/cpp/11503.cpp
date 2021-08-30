#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

class union_find{
private:
	std::vector<int> vi;
	std::vector<int> rank;
    std::vector<int> size;

public:
	union_find(int n){
		vi.assign(n, 0);
		rank.assign(n, 0);
        size.assign(n, 1);

		for(int i=0; i<n; ++i){ vi[i]=i; };
	}
	
	~union_find(){
		vi.clear();
		rank.clear();
	}
	
	int find_set(int a){
		if(vi[a] == a) return a;
		
		vi[a] = find_set(vi[a]);
        size[a] = size[vi[a]];
        return vi[a];
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
			size[pa] += size[pb];
		}else{
			vi[pa] = pb;
			size[pb] += size[pa];
			if(rank[pa] == rank[pb]) rank[pb]++;
		}
	}
	
	int size_of_set(int a){
        return size[find_set(a)];
    }
};

int main(){
    int c, f;
    std::string na, nb;
    std::map<std::string, int> map;

    scanf("%d", &c);
    while(c--){
        map.clear();
        scanf("%d", &f);
        union_find u(f*2);

        while(f--){
            std::cin >> na >> nb;
            if(map.find(na) == map.end()) map[na] = map.size();
            if(map.find(nb) == map.end()) map[nb] = map.size();
            u.union_set(map[na], map[nb]);
            printf("%d\n", u.size_of_set(map[na]));
        }
    }

    return 0;
}
