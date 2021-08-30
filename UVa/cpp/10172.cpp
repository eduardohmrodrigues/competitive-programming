#include <cstdio>
#include <stack>
#include <queue>
#include <vector>

void clear(std::queue<int> b[105]){
	for(int i=0; i<105; i++) {
		std::queue<int> empty;
		b[i].swap(empty);
	}
}

void clear(std::stack<int> *c){
	std::stack<int> empty;
	c->swap(empty);
}

bool finishJob(std::stack<int> carrier, std::queue<int> b[105], int stations){
	bool finished = carrier.size() == 0;
	for(int i=1; i<=stations && finished; i++){
		finished &= b[i].empty();
	}

	return finished;
}

int process(std::stack<int> *carrier, std::queue<int> b[105], int myCapacity, int bCapacity, int currentCargo){
	int time = 0;

	while(!(*carrier).empty()){
		if((*carrier).top() == currentCargo){
			(*carrier).pop();
		}else if(b[currentCargo].size() < bCapacity){
			b[currentCargo].push((*carrier).top());
			(*carrier).pop();
		}else{
			break;
		}
		time++;
	}

	while(!b[currentCargo].empty() && (*carrier).size() < myCapacity){
		(*carrier).push(b[currentCargo].front());
		b[currentCargo].pop();
		time++;
	}

	return time;
}

int main(){
	int cases, stations, myCapacity, bCapacity, q, aux, minutes;
	bool firstMove;
	std::stack<int> carrier;
	std::queue<int> b[105];
	scanf("%d", &cases);

	while(cases--){
		clear(b);
		clear(&carrier);
		minutes = 0;
		firstMove = true;
		scanf("%d %d %d", &stations, &myCapacity, &bCapacity);

		for(int i=1; i<=stations; i++){
			scanf("%d", &q);
			for(int j=0; j<q; j++){
				scanf("%d", &aux);
				b[i].push(aux);
			}
		}
		
		aux = 0;
		while(!finishJob(carrier, b, stations)){
			if(!firstMove) minutes += 2;
			firstMove = false;
			minutes += process(&carrier, b, myCapacity, bCapacity, aux+1);
			aux++;
			aux = aux%stations;
		}
		printf("%d\n", minutes);
	}

	return 0;
}
