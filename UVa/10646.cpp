#include <cstdio>
#include <iostream>
#include <vector>

int getCardValue(std::string card){
	int ic = card[0] - '0';
	if(ic >= 2 && ic <= 9) return ic;
	else return 10;
}

int main(){
	int tests, x, y, amountToRemove, c = 1;
	std::string card;
	std::vector<std::string> pile, hand;
	scanf("%d", &tests);

	while(tests--){
		pile.clear();
		hand.clear();
		y = 0;
		x = 0;
		amountToRemove = 0;

		for(int i=0; i<52; i++){
			std::cin >> card;
			if(i<27) pile.push_back(card);
			else hand.push_back(card);
		}

		for(int i=0; i<3 && pile.size() > 0; i++){
			x = getCardValue(pile[pile.size()-1]);
			y += x;
			amountToRemove = 11 - x;
			if(pile.size() <= amountToRemove) pile.clear();
			else pile.erase(pile.end() - amountToRemove, pile.end());
		}

		if(pile.size() >= y){
			std::cout << "Case " << c << ": " << pile[y-1] << std::endl;
		}else{
			std::cout << "Case " << c << ": " << hand[y-(pile.size()+1)] << std::endl;
		}

		c++;
	}

	return 0;
}
