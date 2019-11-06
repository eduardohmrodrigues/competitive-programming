#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> split(std::string str, std::string delimiter){
	std::string s = str;
	std::vector<std::string> out;
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

int main(){
	std::vector<std::string> scoreboard;
	std::string str;
	int score, round, pointsRead;
	while(std::getline(std::cin, str) && str.compare("Game Over") != 0){
		score = 0;
		round = 1;
		pointsRead = 0;
		scoreboard.clear();
		scoreboard = split(str, " ");
//		limit = scoreboard[scoreboard.size()-3][0] == 'X' ? scoreboard.size()-2 : (scoreboard[scoreboard.size()-2][0] == '/' ? scoreboard.size()-1 : scoreboard.size());
//		std::cout << limit << " limit" << std::endl;
		for(int i=0; i<scoreboard.size(); i++){
//			std::cout << "i=" << i << " | str=" << scoreboard[i] << std::endl;
			if(scoreboard[i][0] == '/'){
//				std::cout << "Vou somar ao " << score << " o valor de " << 10 - std::stoi(scoreboard[i-1]) << std::endl;
				score += 10 - std::stoi(scoreboard[i-1]);
				
				if(round < 10){
					if(scoreboard[i+1][0] == 'X') score += 10;
					else score += std::stoi(scoreboard[i+1]);
				}
				round++;
				pointsRead = 0;
			}else if(scoreboard[i][0] == 'X'){
				score += 10;
				
				if(round < 10){
					if(scoreboard[i+1][0] == 'X') score += 10;
					else score += std::stoi(scoreboard[i+1]);
				}

				if(round < 10){
					if(scoreboard[i+2][0] == '/') score += 10 - std::stoi(scoreboard[i+1]);
					else if(scoreboard[i+2][0] == 'X') score += 10;
					else score += std::stoi(scoreboard[i+2]);
				}
				round++;
			}else{
				score += std::stoi(scoreboard[i]);
				pointsRead++;
				if(pointsRead == 2){
					round++;
					pointsRead = 0;
				}
			}
		}
		
//		score = score > 300 ? 300 : score;
		printf("%d\n", score);
	}

	return 0;
}
