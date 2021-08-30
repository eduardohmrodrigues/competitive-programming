#include <vector>
#include <cstdio>
#include <iostream>
#include <ctype.h>
#include <algorithm>

#define vecstr std::vector<std::string>
#define vecvecstr std::vector<vecstr>

vecstr split(std::string str, std::string delimiter){
	std::string s = str;
	vecstr out;
	out.clear();

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    //std::cout << token << std::endl;
	    out.push_back(token);
	    s.erase(0, pos + delimiter.length());
	}
	out.push_back(s);
	//std::cout << s << std::endl;
	return out;
}

void clearBoard(vecvecstr *vec){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			(*vec)[i][j] = "0";
		}
	}
}

int clamp(int v, int a, int b){
	if(v < a) return a;
	if(v > b) return b;
	return v;
}

void populateBoard(std::string boardStr, vecvecstr *board){
//	std::cout << "Vou popular cm a str: " << boardStr << std::endl;
	vecstr rows = split(boardStr, "/");

	int y;
	for(int i=0; i<rows.size(); i++){
//		std::cout << rows[i] << ": ";
		y = 0;
		for(int j=0; j<rows[i].length(); j++, y++){
//			std::cout << rows[i][j] << " ";
			if(isdigit(rows[i][j])){
				y += rows[i][j] - '0';
				--y;
			}else{
				(*board)[i][y] = rows[i][j];
			}
		}

//		std::cout << std::endl;
	}
}

void printBoard(vecvecstr board){
	for(int i=0; i<board.size(); i++){
		std::cout << "{ ";
		for(int j=0; j<board[i].size(); j++){
			std::cout << board[i][j] << " ";
		}
		
		std::cout << "}" << std::endl;
	}
	std::cout << std::endl;
}

bool containsPiece(vecvecstr *board, int i, int j){
	return i < 8 && i > -1 && j < 8 && j > -1 && (*board)[i][j][0] != '0';
}

void processPiece(vecvecstr *board, vecvecstr *boardAttack, char piece, int x, int y){
	int movementDir = 0;
//	std::cout << "Vou sacar a peca " << piece << " na posicao " << x << ", " << y << std::endl;
	switch(piece){
		case 'p':
			movementDir = 1;
			if(x+movementDir > 7 || x + movementDir < 0) break;

			if(y>0) (*boardAttack)[x+movementDir][y-1] = "px/" + (*boardAttack)[x+movementDir][y-1];
			//(*boardAttack)[x+movementDir][y]           = "px/" + (*boardAttack)[x+movementDir][y];
			if(y<7) (*boardAttack)[x+movementDir][y+1] = "px/" + (*boardAttack)[x+movementDir][y+1];
			//if(x == 1 && !containsPiece(board, 2, y)){
			//	(*boardAttack)[x+2*movementDir][y] = "px/" + (*boardAttack)[x+2*movementDir][y];
			//}
			break;
		case'P' :
			movementDir = -1;
			if(x+movementDir > 7 || x + movementDir < 0) break;

			if(y>0) (*boardAttack)[x+movementDir][y-1] = "Px/" + (*boardAttack)[x+movementDir][y-1];
			//(*boardAttack)[x+movementDir][y]           = "Px/" + (*boardAttack)[x+movementDir][y];
			if(y<7) (*boardAttack)[x+movementDir][y+1] = "Px/" + (*boardAttack)[x+movementDir][y+1];
			//if(x == 6 && !containsPiece(board, 5, y)){
			//	(*boardAttack)[x+2*movementDir][y] = "Px/" + (*boardAttack)[x+2*movementDir][y];
			//}
			break;
		case 'r':
			for(int i=x+1; i<8; ++i){
				(*boardAttack)[i][y] = "rx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int i=x-1; i>-1; --i){
				(*boardAttack)[i][y] = "rx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int j=y+1; j<8; ++j){
				(*boardAttack)[x][j] = "rx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			for(int j=y-1; j>-1; --j){
				(*boardAttack)[x][j] = "rx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			break;
		case 'R':
			for(int i=x+1; i<8; ++i){
				(*boardAttack)[i][y] = "Rx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int i=x-1; i>-1; --i){
				(*boardAttack)[i][y] = "Rx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int j=y+1; j<8; ++j){
				(*boardAttack)[x][j] = "Rx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			for(int j=y-1; j>-1; --j){
				(*boardAttack)[x][j] = "Rx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			break;
		case 'n':
			if(x+1 < 8){
				if(y+2 < 8){(*boardAttack)[x+1][y+2] = "nx/" + (*boardAttack)[x+1][y+2];}
				if(y-2 > -1){(*boardAttack)[x+1][y-2] = "nx/" + (*boardAttack)[x+1][y-2];}
			}

			if(x+2 < 8){
				if(y+1 < 8){(*boardAttack)[x+2][y+1] = "nx/" + (*boardAttack)[x+2][y+1];}
				if(y-1 > -1){(*boardAttack)[x+2][y-1] = "nx/" + (*boardAttack)[x+2][y-1];}
			}

			if(x-1 > -1){
				if(y+2 < 8){(*boardAttack)[x-1][y+2] = "nx/" + (*boardAttack)[x-1][y+2];}
				if(y-2 > -1){(*boardAttack)[x-1][y-2] = "nx/" + (*boardAttack)[x-1][y-2];}
			}

			if(x-2 > -1){
				if(y+1 < 8){(*boardAttack)[x-2][y+1] = "nx/" + (*boardAttack)[x-2][y+1];}
				if(y-1 > -1){(*boardAttack)[x-2][y-1] = "nx/" + (*boardAttack)[x-2][y-1];}
			}
			break;
		case 'N':
			if(x+1 < 8){
				if(y+2 < 8){(*boardAttack)[x+1][y+2] = "Nx/" + (*boardAttack)[x+1][y+2];}
				if(y-2 > -1){(*boardAttack)[x+1][y-2] = "Nx/" + (*boardAttack)[x+1][y-2];}
			}

			if(x+2 < 8){
				if(y+1 < 8){(*boardAttack)[x+2][y+1] = "Nx/" + (*boardAttack)[x+2][y+1];}
				if(y-1 > -1){(*boardAttack)[x+2][y-1] = "Nx/" + (*boardAttack)[x+2][y-1];}
			}

			if(x-1 > -1){
				if(y+2 < 8){(*boardAttack)[x-1][y+2] = "Nx/" + (*boardAttack)[x-1][y+2];}
				if(y-2 > -1){(*boardAttack)[x-1][y-2] = "Nx/" + (*boardAttack)[x-1][y-2];}
			}

			if(x-2 > -1){
				if(y+1 < 8){(*boardAttack)[x-2][y+1] = "Nx/" + (*boardAttack)[x-2][y+1];}
				if(y-1 > -1){(*boardAttack)[x-2][y-1] = "Nx/" + (*boardAttack)[x-2][y-1];}
			}
			break;
		case 'b':
			for(int i=x+1, j=y+1; i<8&&j<8; ++i, ++j){
				(*boardAttack)[i][j] = "bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y+1; i>-1&&j<8; --i, ++j){
				(*boardAttack)[i][j] = "bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x+1,j=y-1; i<8&&j>-1; ++i,--j){
				(*boardAttack)[i][j] = "bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y-1; i>-1&&j>-1; --i,--j){
				(*boardAttack)[i][j] = "bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			break;
		case 'B':
			for(int i=x+1, j=y+1; i<8&&j<8; ++i, ++j){
				(*boardAttack)[i][j] = "Bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y+1; i>-1&&j<8; --i, ++j){
				(*boardAttack)[i][j] = "Bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x+1,j=y-1; i<8&&j>-1; ++i,--j){
				(*boardAttack)[i][j] = "Bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y-1; i>-1&&j>-1; --i,--j){
				(*boardAttack)[i][j] = "Bx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			break;
		case 'q':
			for(int i=x+1; i<8; ++i){
				(*boardAttack)[i][y] = "qx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int i=x-1; i>-1; --i){
				(*boardAttack)[i][y] = "qx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int j=y+1; j<8; ++j){
				(*boardAttack)[x][j] = "qx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			for(int j=y-1; j>-1; --j){
				(*boardAttack)[x][j] = "qx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			for(int i=x+1, j=y+1; i<8&&j<8; ++i, ++j){
				(*boardAttack)[i][j] = "qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y+1; i>-1&&j<8; --i, ++j){
				(*boardAttack)[i][j] = "qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x+1,j=y-1; i<8&&j>-1; ++i,--j){
				(*boardAttack)[i][j] = "qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y-1; i>-1&&j>-1; --i,--j){
				(*boardAttack)[i][j] = "qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			break;
		case 'Q':
			for(int i=x+1; i<8; ++i){
				(*boardAttack)[i][y] = "Qx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int i=x-1; i>-1; --i){
				(*boardAttack)[i][y] = "Qx/" + (*boardAttack)[i][y];
				if(containsPiece(board, i, y)) break;
			}
			for(int j=y+1; j<8; ++j){
				(*boardAttack)[x][j] = "Qx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			for(int j=y-1; j>-1; --j){
				(*boardAttack)[x][j] = "Qx/" + (*boardAttack)[x][j];
				if(containsPiece(board, x, j)) break;
			}
			for(int i=x+1, j=y+1; i<8&&j<8; ++i, ++j){
				(*boardAttack)[i][j] = "Qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y+1; i>-1&&j<8; --i, ++j){
				(*boardAttack)[i][j] = "Qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x+1,j=y-1; i<8&&j>-1; ++i,--j){
				(*boardAttack)[i][j] = "Qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			for(int i=x-1, j=y-1; i>-1&&j>-1; --i,--j){
				(*boardAttack)[i][j] = "Qx/" + (*boardAttack)[i][j];
				if(containsPiece(board, i, j)) break;
			}
			break;
		case 'k':
			for(int i=-1; i<=1; i++){
				if(x+i < 0 || x+i > 7) continue;

				for(int j=-1; j<=1; j++){
					if(y+j < 0 || y+j > 7) continue;
					if(i != 0 || j != 0) (*boardAttack)[x+i][y+j] = "kx/" + (*boardAttack)[x+i][y+j];
				}
			}
			break;
		case 'K':
			for(int i=-1; i<=1; i++){
				if(x+i < 0 || x+i > 7) continue;

				for(int j=-1; j<=1; j++){
					if(y+j < 0 || y+j > 7) continue;
					if(i != 0 || j != 0) (*boardAttack)[x+i][y+j] = "Kx/" + (*boardAttack)[x+i][y+j];
				}
			}
			break;
		default:
			break;
	}
}

void processBoard(vecvecstr *board, vecvecstr *boardAttack){
	for(int i=0; i<board->size(); i++){
		for(int j=0; j<(*board)[i].size(); j++){
			std::string element = ((*board)[i][j]);
			if(element.length() == 1 && element[0] != '0') processPiece(board, boardAttack, element[0], i, j);	
		}
	}
}

int getEmptySlots(vecvecstr board, vecvecstr boardAttack){
	int sum = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(board[i][j][0] == '0' && boardAttack[i][j][0] == '0') sum++;
		}
	}

	return sum;
}

int main(){
	vecvecstr board(8, std::vector<std::string>(8));
	vecvecstr boardAttack(8, std::vector<std::string>(8));
	std::string str;
	int emptySlots;

	while(std::cin >> str){
		clearBoard(&board);
		clearBoard(&boardAttack);
		emptySlots = 0;

		populateBoard(str, &board);
//		printBoard(board);
//		std::cout << "=============" << std::endl << std::endl;
		processBoard(&board, &boardAttack);
//		printBoard(board);
//		std::cout << "=============" << std::endl << std::endl;
//		printBoard(boardAttack);
//		std::cout << "=============" << std::endl << std::endl;
		
		emptySlots = getEmptySlots(board, boardAttack);
		std::cout << emptySlots << std::endl;
	}

	//for(int i=0; i<out.size(); i++) std::cout << out[i] << " ";
//	std::cout << std::endl;
	return 0;
}
