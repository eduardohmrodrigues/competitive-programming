#include <cstdio>
#include <iostream>
#include <vector>

#define vecc std::vector<char>
#define vvc std::vector<vecc>

void clear(vvc *vec){
	for(int i=0; i<vec->size(); i++){
		(*vec)[i].clear();
	}

	vec->clear();
}

void print(vvc vec){
	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec[i].size(); j++){
			std::cout << vec[i][j];
		}

		std::cout << std::endl;
	}
}

void process(vvc vec, vvc *proc){
	for(int i=0; i<vec.size(); i++)
	for(int j=0; j<vec[i].size(); j++)
	{
		if(i-1>=0){
			int x = i-1, y = j;
			if(vec[i][j] == 'R' && vec[x][y] == 'S'){
				(*proc)[x][y] = 'R';
			}else if(vec[i][j] == 'S' && vec[x][y] == 'P'){
				(*proc)[x][y] = 'S';
			}else if(vec[i][j] == 'P' && vec[x][y] == 'R'){
				(*proc)[x][y] = 'P';
			}
		}

		if(i+1<vec.size()){
			int x = i+1, y = j;
			if(vec[i][j] == 'R' && vec[x][y] == 'S'){
				(*proc)[x][y] = 'R';
			}else if(vec[i][j] == 'S' && vec[x][y] == 'P'){
				(*proc)[x][y] = 'S';
			}else if(vec[i][j] == 'P' && vec[x][y] == 'R'){
				(*proc)[x][y] = 'P';
			}
		}

		if(j-1>=0){
			int x = i, y = j-1;
			if(vec[i][j] == 'R' && vec[x][y] == 'S'){
				(*proc)[x][y] = 'R';
			}else if(vec[i][j] == 'S' && vec[x][y] == 'P'){
				(*proc)[x][y] = 'S';
			}else if(vec[i][j] == 'P' && vec[x][y] == 'R'){
				(*proc)[x][y] = 'P';
			}
		}

		if(j+1<vec[i].size()){
			int x = i, y = j+1;
			if(vec[i][j] == 'R' && vec[x][y] == 'S'){
				(*proc)[x][y] = 'R';
			}else if(vec[i][j] == 'S' && vec[x][y] == 'P'){
				(*proc)[x][y] = 'S';
			}else if(vec[i][j] == 'P' && vec[x][y] == 'R'){
				(*proc)[x][y] = 'P';
			}
		}
	}
}

int main(){
	vvc grid, grid2;
	std::string str;
	int r, c, n, t, l=0;
	scanf("%d", &t);

	while(t--){
		if(l>0) printf("\n");
		clear(&grid);
		clear(&grid2);

		scanf("%d %d %d", &r, &c, &n);
		grid = vvc(r, vecc(c));
		grid2 = vvc(r, vecc(c));

		if(r != 0 && c != 0){
			for(int i=0; i<r; i++){
				std::cin >> str;
				for(int j=0; j<c; j++){
					grid[i][j] = str[j];
					grid2[i][j] = str[j];
				}
			}
			
			for(int i=0; i<n; i++) {
				process(grid, &grid2);
				for(int k=0; k<grid.size(); k++){
					grid[k].clear();
					grid[k] = grid2[k];
				}
			}

	//		print(grid);
	//		printf("\n");
			print(grid2);
	//		printf("===========\n");
		}
		l++;
	}
	
	return 0;
}
