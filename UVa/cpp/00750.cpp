#include <cstdio>
#include <iostream>
#include <cmath>

const int MAX_BOARD_DIM = 8;

bool place(int cr, int cc, int r, int c, int board[MAX_BOARD_DIM]){
	if(cr == r && cc != c || cc == c && cr != r) return false;

	int i;
	for(int j=0; j<cc; ++j){
		i = board[j];
		if(i == cr) return false;
		if(j == cc) return false;
		if(std::abs(cr-i) == std::abs(cc-j)) return false;	
	}

	return true;
}

void backtrack(int currCol, int r, int c, int board[MAX_BOARD_DIM], int *tc){
	if(currCol == MAX_BOARD_DIM && board[c] == r){
		if((*tc) < 10) printf(" ");
		printf("%d      ", (*tc));
		for(int j=0; j<MAX_BOARD_DIM; ++j){
			if(j>0) printf(" ");
			printf("%d", board[j]+1);
		}
		printf("\n");
		(*tc)++;
	}

	for(int i=0; i<MAX_BOARD_DIM; ++i){
		if(place(i, currCol, r, c, board)){
			board[currCol] = i;
			backtrack(currCol+1, r, c, board, tc);
		}
	}

	board[currCol] = -1;
}

int main(){
	int t, row, col, c, board[MAX_BOARD_DIM];
	bool first = true;
	scanf("%d%*c", &t);

	while(t--){
		if(!first) printf("\n");
		c = 1;
		first = false;
		scanf("%d %d%*c", &row, &col);
		--row; --col;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0, row, col, board, &c);

	}

	return 0;
}
