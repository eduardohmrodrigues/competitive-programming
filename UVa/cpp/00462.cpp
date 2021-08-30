#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

char suitArray[] = {'S', 'H', 'D', 'C'};

int getPoints(char card){
	if(card == 'A') return 4;
	if(card == 'K') return 3;
	if(card == 'Q') return 2;
	if(card == 'J') return 1;

	return 0;
}

void insertValueOnMap(std::map<char, std::vector<char>> *map, char key, char val){
	if((*map).find(key) == (*map).end()){
		(*map)[key] = std::vector<char>();
	}

	(*map)[key].push_back(val);
}

void insertCardOnMaps(std::map<char, std::vector<char>> *cardToSuit, std::map<char, std::vector<char>> *suitToCard, std::string card){
	insertValueOnMap(cardToSuit, card[0], card[1]);
	insertValueOnMap(suitToCard, card[1], card[0]);
}

void clearMaps(std::map<char, std::vector<char>> *map){
	for(std::map<char, std::vector<char>>::iterator it = map->begin(); it != map->end(); it++){
		it->second.clear();
	}
	
	map->clear();
}

void populateSuitMap(std::map<char, std::vector<char>> *map){
	(*map)['S'] = std::vector<char>();
	(*map)['H'] = std::vector<char>();
	(*map)['D'] = std::vector<char>();
	(*map)['C'] = std::vector<char>();
}

void populateCardMap(std::map<char, std::vector<char>> *map){
	(*map)['A'] = std::vector<char>();
	(*map)['1'] = std::vector<char>();
	(*map)['2'] = std::vector<char>();
	(*map)['3'] = std::vector<char>();
	(*map)['4'] = std::vector<char>();
	(*map)['5'] = std::vector<char>();
	(*map)['6'] = std::vector<char>();
	(*map)['7'] = std::vector<char>();
	(*map)['8'] = std::vector<char>();
	(*map)['9'] = std::vector<char>();
	(*map)['T'] = std::vector<char>();
	(*map)['J'] = std::vector<char>();
	(*map)['Q'] = std::vector<char>();
	(*map)['K'] = std::vector<char>();
}

bool suitStopped(std::map<char, std::vector<char>> suitMap, char suit){
	std::vector<char> cards = suitMap[suit];
	return std::find(cards.begin(), cards.end(), 'A') != cards.end() ||
		std::find(cards.begin(), cards.end(), 'K') != cards.end() && cards.size()-1 > 0 ||
		std::find(cards.begin(), cards.end(), 'Q') != cards.end() && cards.size()-1 > 1;
}

void printMap(std::map<char, std::vector<char>> map){
	for(std::map<char, std::vector<char>>::iterator it = map.begin(); it != map.end(); it++){
		printf("%c { ", it->first);
		for(int i=0; i<it->second.size(); i++){
			if(i>0) printf(", ");

			printf("%c", it->second[i]);
		}
		
		printf(" }\n");
	}
}

int main(){
	std::map<char, std::vector<char>> cardToSuit;
	std::map<char, std::vector<char>> suitToCard;
	std::string cardstr;
	int points, noTrumpPoints, maxCardsOnSuit;
	char selectedSuit;
	bool sStopped = false, hStopped = false, dStopped = false, cStopped = false;

	while(std::cin >> cardstr){
		clearMaps(&cardToSuit);
		clearMaps(&suitToCard);
		populateCardMap(&cardToSuit);
		populateSuitMap(&suitToCard);
			
		points = 0;
		noTrumpPoints = 0;
		maxCardsOnSuit = 0;
		selectedSuit = 'E';
		sStopped = false; hStopped = false; dStopped = false; cStopped = false;

		points += getPoints(cardstr[0]);
		insertCardOnMaps(&cardToSuit, &suitToCard, cardstr);
		
		for(int i=1; i<13; i++){
			std::cin >> cardstr;
			points += getPoints(cardstr[0]);
			insertCardOnMaps(&cardToSuit, &suitToCard, cardstr);
		}

//		printf("Card To Suit:\n");
//		printMap(cardToSuit);
//		printf("Suit To Card:\n");
//		printMap(suitToCard);
		std::vector<char> suits;
		suits.clear();

		//Subtract a point for any king of a suit in wich the hand holds no other cards
		suits = cardToSuit['K'];
		for(int i=0; i<suits.size(); i++){
			if(suitToCard[suits[i]].size()-1 == 0){
				points--;
			}
		}

		//Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
		suits = cardToSuit['Q'];
		for(int i=0; i<suits.size(); i++){
			if(suitToCard[suits[i]].size()-1 < 2){
				points--;
			}
		}

		//Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
		suits = cardToSuit['J'];
		for(int i=0; i<suits.size(); i++){
			if(suitToCard[suits[i]].size()-1 < 3){
				points--;
			}
		}

		noTrumpPoints = points;
		
		for(std::map<char, std::vector<char>>::iterator it = suitToCard.begin(); it != suitToCard.end(); it++){
			//Add a point for each suit in which the hand contains exactly two cards.
			if(it->second.size() == 2){
				points++;
			}
			//Add two points for each suit in which the hand contains exactly one card.
			//Add two points for each suit in which the hand contains no cards
			if(it->second.size() <= 1){
				points+=2;
			}
		}
		
//		printf("%d\n", points);

		sStopped = suitStopped(suitToCard, 'S');
		hStopped = suitStopped(suitToCard, 'H');
		dStopped = suitStopped(suitToCard, 'D');
		cStopped = suitStopped(suitToCard, 'C');
		
		if(noTrumpPoints >= 16 && sStopped && hStopped && dStopped && cStopped){
			printf("BID NO-TRUMP\n");
		}else if(points >= 14){
			maxCardsOnSuit = 0;
			selectedSuit = 'E';
			for(int i=0; i<4; i++){
				if(suitToCard[suitArray[i]].size() > maxCardsOnSuit){
					maxCardsOnSuit = suitToCard[suitArray[i]].size();
					selectedSuit = suitArray[i];
				}
			}
			
			printf("BID %c\n", selectedSuit);
		}else{
			printf("PASS\n");
		}

		suits.clear();
	}

	return 0;
}
