#include <cstdio>
#include <iostream>

int main(){
	int n;
	std::string seq;
	scanf("%d", &n);

	while(n > 0){
		std::cin >> seq;
	//	std::cout << "TP " << seq  << std::endl;
	
		if(seq.length() == 1 && (seq[0] == '1' || seq[0] == '4')){
				printf("+\n");
		}else if(seq.length() == 2 && seq[0] == '7' && seq[1] == '8'){
				printf("+\n");
		}else if(seq[seq.length()-2] == '3' && seq[seq.length()-1] == '5'){
				printf("-\n");
		}else if(seq[0] == '9' && seq[seq.length()-1] == '4'){
				printf("*\n");
		}else{
				printf("?\n");
		}

		--n;
	}

	return 0;
}
