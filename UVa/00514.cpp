#include <cstdio>
#include <stack>
#include <vector>

void checkStack(std::stack<int> *stack, std::vector<int> *vec){
	while(!stack->empty() && vec->size() > 0){
		if(stack->top() == (*vec)[0]){
			vec->erase(vec->begin());
			stack->pop();
		}else{
			break;
		}
	}
}

int main(){
	std::stack<int> stack;
	std::vector<int> vec;
	int n, x;

	while(scanf("%d", &n) != EOF && n != 0){

		while(scanf("%d", &x) && x != 0){
			while(!stack.empty()) stack.pop();
			vec.clear();

			vec.push_back(x);
			for(int i=0; i<n-1; ++i){
				scanf("%d", &x);
				vec.push_back(x);
			}

			for(int i=1; i<=n; ++i){
				if(vec.size() == 0) break;
				stack.push(i);
				checkStack(&stack, &vec);				
			}
			checkStack(&stack, &vec);				
			
			if(vec.size()==0) printf("Yes\n");
			else printf("No\n");
		}
		
		printf("\n");
	}

	return 0;
}
