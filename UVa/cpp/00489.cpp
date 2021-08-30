#include <cstdio>
#include <iostream>
#include <algorithm>

int main(){
	int round, count;
	std::string word, guess, used;
	
	while(scanf("%d", &round) && round != -1){
		std::cin >> word;
		std::cin >> guess;
		used = "";
		count = 0;

		for(int i=0; i<guess.length() && count<7 && word.length() > 0; i++){
			if(used.find(guess[i]) != std::string::npos){
				continue;
			}

			used += guess[i];

			if(word.find(guess[i]) != std::string::npos){
				word.erase(std::remove(word.begin(), word.end(), guess[i]), word.end());
			}else{
				count++;
			}
		}
		
		printf("Round %d\n", round);
		if(count == 7){
			printf("You lose.\n");
		}else if(word.length() == 0){
			printf("You win.\n");
		}else{
			printf("You chickened out.\n");
		}
	}

	return 0;
}
