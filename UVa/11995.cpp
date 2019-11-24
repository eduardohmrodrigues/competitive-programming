#include <cstdio>
#include <queue>
#include <stack>

int main(){
	int n, cmd, x;
	bool isQueue, isPqueue, isStack;

	while(scanf("%d", &n) != EOF){
		std::queue<int> queue;
		std::priority_queue<int, std::vector<int>, std::less<int>> pq;
		std::stack<int> stack;
		isQueue = true; isPqueue = true; isStack = true;

		while(n--){
			scanf("%d %d", &cmd, &x);

			if(cmd == 1){
				queue.push(x);
				pq.push(x);
				stack.push(x);
			}else{
				if(isQueue){
					if(queue.size() > 0 && queue.front() == x) queue.pop();
					else isQueue = false;
				}

				if(isPqueue){
					if(pq.size() > 0 && pq.top() == x) pq.pop();
					else isPqueue = false;
				}

				if(isStack){
					if(stack.size() > 0 && stack.top() == x) stack.pop();
					else isStack = false;
				}
			}
		}

		if(!isStack && !isQueue && !isPqueue){
			printf("impossible\n");
		}else if((isStack && (isQueue || isPqueue)) || (isQueue && isPqueue)){
			printf("not sure\n");
		}else if(isStack){
			printf("stack\n");
		}else if(isQueue){
			printf("queue\n");
		}else if(isPqueue){
			printf("priority queue\n");
		}else{
			printf("never happen\n");
		}
	}

	return 0;
}
