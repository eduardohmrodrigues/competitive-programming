#include <cstdio>
#include <vector>

int findBestMatch(std::vector<int> hand, int card){
	int mostNeutralLose = 53;
	int indexOfNeutralLose = -1;

	// From which card can I lose with the little difference
	for(int i=0; i<hand.size(); i++){
		int diff = hand[i]-card;
		if(diff > 0 && diff < mostNeutralLose){
			mostNeutralLose = diff;
			indexOfNeutralLose = i;		
		}
	}

	// If I cannot lose, from which card can I win in the most useless way
	if(indexOfNeutralLose == -1){
		for(int i=0; i<hand.size(); i++){
			int diff = hand[i]-card;
			if(diff < 0 && diff < mostNeutralLose){
				mostNeutralLose = diff;
				indexOfNeutralLose = i;		
			}
		}
	}

	return indexOfNeutralLose;
}

int main(){
	int a, b, c, x, y, z, aux;
	int nlx, nly;
	std::vector<int> hand;

	while(scanf("%d %d %d %d %d", &a, &b, &c, &x, &y) && a != 0 && b != 0 && c != 0 && x != 0 && y != 0){
		hand.clear();
		hand.push_back(a); hand.push_back(b); hand.push_back(c);	
		
		// Order the prince hand
		if(x < y) { aux = x; x = y; y = aux; }

		// aux is gonna be used to count the amount of loses now
		aux = 0;
		// Find the most idiot lose case for the best card of the princes hand (if it exists)
		nlx = findBestMatch(hand, x);
		aux += x < hand[nlx] ? 1 : 0;
		hand.erase(hand.begin()+nlx);
		
		// Find the most idiot lose case for the worst card of the princes hand (if it exists)
		nly = findBestMatch(hand, y);
		aux += y < hand[nly] ? 1 : 0;
		hand.erase(hand.begin()+nly);

		if(aux == 2){
			printf("-1\n");
		}else if(aux == 0){
			for(int i=1; i<53; i++){
				if(i != a && i != b && i != c && i != x && i != y){
					printf("%d\n", i);
					break;
				}
			}
		}else{
			bool found = false;
			for(int i=hand[0]+1; i<53; i++){
				if(i != a && i != b && i != c && i != x && i != y){
					printf("%d\n", i);
					found = true;
					break;
				}
			}

			if(!found){
				printf("-1\n");
			}
		}
	}

	return 0;
}
