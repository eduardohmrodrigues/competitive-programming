#include <cstdio>
#include <vector>
#include <math.h>
#include <iostream>

struct interval{
	int start;
	int end;
};

void printHour(int seconds){
	int sec = seconds%60;
	int min = seconds/60;
	int hour = min/60;
	min %= 60;

	std::cout << "0" << hour << ":";

	if(min < 10) std::cout << "0";
	std::cout << min << ":";

	if(sec < 10) std::cout << "0";
	std::cout << sec << std::endl;
}

int intersect(std::vector<std::vector<interval>> intervals, int index, interval curr = {.start=-1, .end=-1}){
	int inter = -1;
	interval temp;
	bool found = false;

	if(index == intervals.size()){
		return curr.start;
	}

	for(int i=0; i<intervals[index].size() && !found; i++){
		if(curr.start == -1){
			inter = intersect(intervals, index+1, intervals[index][i]);
			found = inter != -1;
		}else{
			temp = {.start=std::max(curr.start, intervals[index][i].start), .end=std::min(curr.end, intervals[index][i].end)};
			if(temp.start < temp.end){
				inter = intersect(intervals, index+1, temp);
				found = inter != -1;
			}
		}
	}

	return inter;
}

int main(){
	std::vector<int> cycles;
	std::vector<std::vector<interval>> intervals;
		
	int aux, zeros=0, lowest, limit = 18002;

	while(zeros < 2){
		lowest = 999999;

		while(scanf("%d", &aux)){
			if(aux == 0){
				++zeros;
				break;
			}
			
			zeros = 0;
			lowest = lowest < aux ? lowest : aux;
			cycles.push_back(aux);
		}

		if(cycles.size()>1){
			intervals.clear();
			for(int i=0; i<cycles.size(); ++i){
				intervals.push_back(std::vector<interval>());

				aux = cycles[i] == lowest ? 2 : 1;
				for(int j=aux; ; ++j){
					int start = cycles[i]*((j-1)*2);
					int end = (cycles[i]*((j-1)*2))+(cycles[i]-5);
					
					if(start >= limit) break;
					if(end >= limit) end = limit-1;

					intervals[i].push_back(interval{.start=start, .end=end});
				}
			}
			
			aux = intersect(intervals, 0);
			
			if(aux == -1) printf("Signals fail to synchronise in 5 hours\n");
			else printHour(aux);

			intervals.clear();
			cycles.clear();
		}
	}

	return 0;
}
