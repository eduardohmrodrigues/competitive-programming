#include <cstdio>
#include <vector>

#define veci std::vector<int>
#define vvi std::vector<veci>

void clear(vvi *vec){
	for(int i=0; i<vec->size(); i++) (*vec)[i].clear();
	vec->clear();
}

void print(vvi vec){
	for(int i=0; i<vec.size(); i++){
		printf("{ ");
		for(int j=0; j<vec[i].size(); j++){
			printf("%d ", vec[i][j]);
		}
		printf("}\n");
	}
}

void mark(vvi *card, int num){
	int col = 0;
	if(num < 16){
		col = 0;
	}else if(num < 31){
		col = 1;
	}else if(num < 46){
		col = 2;
	}else if(num < 61){
		col = 3;
	}else{
		col = 4;
	}

	for(int i=0; i<5; i++){
		if((*card)[i][col] == num){
			(*card)[i][col] = 0;
			return;
		}
	}
}

bool bingo(vvi card){
	bool bingo = true;

	// Check rows
	for(int i=0; i<5; i++){
		bingo = true;
		for(int j=0; j<5 && bingo; j++){
			bingo &= card[i][j] == 0;
		}
		if(bingo) return bingo;
	}

	// Check columns
	for(int j=0; j<5; j++){
		bingo = true;
		for(int i=0; i<5 && bingo; i++){
			bingo &= card[i][j] == 0;
		}

		if(bingo) return bingo;
	}

	// Check diagonal 1
	bingo = true;
	for(int i=0; i<5 && bingo; i++){
		bingo &= card[i][i] == 0;
	}
	if(bingo) return bingo;
	
	// Check diagonal 2
	bingo = true;
	for(int i=0, j=4; j>=0 && bingo; i++, j--){
		bingo &= card[i][j] == 0;
	}
	return bingo;
}

int main(){
	int n, x, round;
	vvi card;
	scanf("%d", &n);

	while(n--){
		clear(&card);
		card = vvi(5, veci(5, 0));
		round = -1;

		for(int i=0; i<25; i++){
			if(i==12) i++;
			scanf("%d", &card[i/5][(i%5)]);
		}

		for(int i=1; i<76; ++i){
			scanf("%d", &x);
			mark(&card, x);
//			print(card);
			if(round == -1 && bingo(card)) round = i;
		}

		printf("BINGO after %d numbers announced\n", round);
//		print(card);
	}

	return 0;
}
