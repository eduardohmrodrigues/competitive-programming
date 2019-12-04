#include <cstdio>
#include <iostream>
#include <cmath>

const int MAX_BOARD_DIM = 16;

bool place(int r, int c, int dim, int board[MAX_BOARD_DIM], bool badBoard[MAX_BOARD_DIM*MAX_BOARD_DIM]){
	if(badBoard[dim*r+c]) return false;

	int i;
	for(int j=0; j<c; ++j){
		i = board[j];
		if(i == r) return false;
		if(j == c) return false;
		if(std::abs(r-i) == std::abs(c-j)) return false;
	}

	return true;
}

void backtrack(int currCol, int dim, int board[MAX_BOARD_DIM], bool badBoard[MAX_BOARD_DIM*MAX_BOARD_DIM], int *tc){
	if(currCol == dim){
		(*tc)++;
		return;
	}
	
	for(int i=0; i<dim; ++i){
		if(place(i, currCol, dim, board, badBoard)){
			board[currCol] = i;
			backtrack(currCol+1, dim, board, badBoard, tc);
		}
	}

	board[currCol] = -1;
}

int main(){
	int d, row, col, counter, board[MAX_BOARD_DIM], test = 1;
	bool badBoard[MAX_BOARD_DIM*MAX_BOARD_DIM];
	std::string str;

	while(scanf("%d%*c", &d) != EOF && d > 0){
		counter = 0;
		for(int i=0; i<d; ++i){
			std::getline(std::cin, str);
			for(int j=0; j<d; ++j){
				if(str[j] == '*') badBoard[i*d+j] = true;
				else badBoard[i*d+j] = false;
			}
		}

		backtrack(0, d, board, badBoard, &counter);
		printf("Case %d: %d\n", test++, counter);
	}

	return 0;
}
