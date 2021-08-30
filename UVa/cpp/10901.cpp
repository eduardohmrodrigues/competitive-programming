#include <cstdio>
#include <iostream>
#include <queue>

struct car{
	int queued;
	int delivered;
};

void popQueue(std::queue<car*> *queue, int time, int n, int t){
	int aux = 0;
	while(queue->size() > 0 && queue->front()->queued <= time && aux < n){
		queue->front()->delivered = time+t;
		queue->pop();
		++aux;
	}
}

int main(){
	int c, n, t, m, time, aux;
	bool onLeft, first = true, la, ra;
	std::queue<car*> left, right;
	car cars[10000];
	std::string side;
	scanf("%d", &c);

	while(c--){
		if(!first) printf("\n");
		first = false;
		scanf("%d %d %d", &n, &t, &m);
		time = 0;
		onLeft = true;

		for(int i=0; i<m; i++){
			std::cin >> aux >> side;
			cars[i] = car{.queued=aux, .delivered=-1};
			if(side.compare("left") == 0){
				left.push(&(cars[i]));
			}else{
				right.push(&(cars[i]));
			}
		}
	
		while(left.size() != 0 || right.size() != 0){
			la = left.size() > 0 && left.front()->queued <= time;
			ra = right.size() > 0 && right.front()->queued <= time;

			if(la && onLeft){
				aux = 0;
				popQueue(&left, time, n, t);
				onLeft = false;
				time += t;
			}else if(ra && !onLeft){
				aux = 0;
				popQueue(&right, time, n, t);
				onLeft = true;
				time += t;

			}else if(la){
				time += t;

				aux = 0;
				popQueue(&left, time, n, t);
				onLeft = false;
				time += t;

			}else if(ra){
				time += t;

				aux = 0;
				popQueue(&right, time, n, t);
				onLeft = true;
				time += t;
			}else{
				time += 1;
			}
		}

		for(int i=0; i<m; i++){
			printf("%d\n", cars[i].delivered);
		}
	}

	return 0;
}
