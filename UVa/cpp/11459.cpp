#include <cstdio>
#include <vector>
#include <map>

int main(){
	int n, a, b, c, s, e, die, player;
	std::vector<int> players;
	std::map<int, int> skips;
	bool stop;

	scanf("%d", &n);

	while(n--){
		players.clear();
		skips.clear();

		scanf("%d %d %d", &a, &b, &c);
		players = std::vector<int>(a, 1);
		
		for(int i=0; i<b; i++){
			scanf("%d %d", &s, &e);
			skips[s] = e;		
		}
		
		stop = false;	
		player=0;
		for(int i=0; i<c; i++){
			scanf("%d", &die);
			if(stop || a <= 0) continue;

			players[player] += die;
			
			if(skips.find(players[player]) != skips.end()){
				players[player] = skips[players[player]];
			}
			
			if(players[player] >= 100){
				players[player] = 100;
				stop=true;
			}
			++player;
			player %= players.size();
		}

		for(int i=0; i<players.size(); i++){
			printf("Position of player %d is %d.\n", i+1, players[i]);
		}
	}

	return 0;
}
