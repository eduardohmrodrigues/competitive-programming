#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define vs  std::vector<std::string>
#define vvs std::vector<vs>
#define vc std::vector<char>
#define vvc std::vector<vc>

vvs C5{
    {".***..", "*...*.", "*****.", "*...*.", "*...*."},//A
    {"****..", "*...*.", "****..", "*...*.", "****.."},//B
    {".****.", "*...*.", "*.....", "*.....", ".****."},//C
    {"****..", "*...*.", "*...*.", "*...*.", "****.."},//D
    {"*****.", "*.....", "***...", "*.....", "*****."},//E
    {"*****.", "*.....", "***...", "*.....", "*....."},//F
    {".****.", "*.....", "*..**.", "*...*.", ".***.."},//G
    {"*...*.", "*...*.", "*****.", "*...*.", "*...*."},//H
    {"*****.", "..*...", "..*...", "..*...", "*****."},//I
    {"..***.", "...*..", "...*..", "*..*..", ".**..."},//J
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."},//K
    {"*.....", "*.....", "*.....", "*.....", "*****."},//L
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."},//M
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."},//N
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."},//O
    {"****..", "*...*.", "****..", "*.....", "*....."},//P
    {".***..", "*...*.", "*...*.", "*..**.", ".****."},//Q
    {"****..", "*...*.", "****..", "*..*..", "*...*."},//R
    {".****.", "*.....", ".***..", "....*.", "****.."},//S
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."},//T
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."},//U
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."},//V
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."},//W
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."},//X
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."},//Y
    {"*****.", "...*..", "..*...", ".*....", "*****."},//Z
    {"......", "......", "......", "......", "......"},//BLANK
};

void readCommand(std::string cmd, std::string *arg1, std::string *arg2, std::string *arg3, std::string *arg4){
	std::cin >> (*arg1);
	std::cin >> (*arg2);
	
	if(cmd.compare(".P") == 0) std::cin >> (*arg3);

	std::getline(std::cin, (*arg4));
	(*arg4) = (*arg4).substr(2, (*arg4).length()-3);

	if(cmd.compare(".L") == 0) (*arg3) = "1";
	else if(cmd.compare(".R") == 0){
		int l = (*arg4).length();
		l = (*arg1).compare("C1") == 0 ? l : l*6;
		(*arg3) = std::to_string(61-l);
	}else if(cmd.compare(".C") == 0){
		int l = (*arg4).length();
		l = (*arg1).compare("C1") == 0 ? l : l*6;
		if(l%2!=0){
			l -= 1;
		}
		(*arg3) = std::to_string(31-(l/2));
	}
}

void process(vvc *vec, std::string a1, std::string a2, std::string a3, std::string a4){
	int row = stoi(a2)-1; int col = stoi(a3)-1;
	if(a1.compare("C1") == 0){
		if(row >= 60) return;
		for(int j=col; j<60 && j-col < a4.length(); j++) {
			if(a4[j-col] == ' ') continue;

			(*vec)[row][j] = a4[j-col];
		}
	}else{	
		if(row >= 60 || col >= 60) return;
		int maxInc = 60-row, curr=0;
		maxInc = maxInc > 5 ? 5 : maxInc;
		for(int j=col, c=0; j<60 && curr<a4.length(); j++, c++){
			if(c == 6){
				c = 0;
				curr++;
				if(curr >= a4.length()) break;
			}
			
			if(j < 0) continue;

			for(int i=0; i<maxInc; i++){
				if(a4[curr] == ' '){
				//	(*vec)[row+i][j] = C5[C5.size()-1][i][c];
				}else if(C5[a4[curr] - 'A'][i][c] != '.'){
					(*vec)[row+i][j] = C5[a4[curr] - 'A'][i][c];
				}
			}
		}
	}
}

void print(vvc vec){
	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec[i].size(); j++){
			std::cout << vec[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for(int i=0; i<60; i++) std::cout << "-";
	std::cout << std::endl << std::endl;
}

void clear(vvc *vec){
	for(int i=0; i<(*vec).size(); i++) (*vec)[i].clear();
	(*vec).clear();
}

int main(){
	std::string cmd = "asd", arg1, arg2, arg3, arg4;
	vvc board;
	bool something = false;

	while(cmd.compare(".exit") != 0){
		clear(&board);
		board = vvc(60, vc(60, '.'));
		cmd = ".exit";

		while(std::cin >> cmd && cmd.compare(".EOP") != 0){
			readCommand(cmd, &arg1, &arg2, &arg3, &arg4);
			process(&board, arg1, arg2, arg3, arg4);
		}

		if(cmd.compare(".EOP") == 0){
			print(board);
			something = false;
		}else{
			cmd = ".exit";
		}
	}
	return 0;
}
