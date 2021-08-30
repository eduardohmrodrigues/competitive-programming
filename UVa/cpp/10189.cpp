#include <cstdio>
#include <iostream>
#include <vector>

#define vvs std::vector<std::vector<std::string>>

void clearField(vvs *vec){
	for(int i=0; i<vec->size(); i++){
		vec[i].clear();
	}

	vec->clear();
}

void printField(vvs vec){
	for(int i=0; i<vec.size(); i++){
//		std::cout << "{ ";
		for(int j=0; j<vec[i].size(); j++){
			std::cout << vec[i][j];
		}
		std::cout << std::endl;
//		std::cout << "}" << std::endl;
	}

//	std::cout << std::endl;
}

vvs getProcessedField(vvs vec){
	vvs processed = vvs(vec.size(), std::vector<std::string>(vec[0].size()));
	int count = 0;
	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec[i].size(); j++){
			if(vec[i][j][0] == '*'){
				processed[i][j] = "*";
			}else{
				count = 0;
				for(int x=-1; x<2; x++){
					for(int y=-1; y<2; y++){
						if(i+x > -1 && i+x < vec.size() && j+y > -1 && j+y < vec[i].size() && vec[i+x][j+y][0]=='*'){
							count++;
						}
					}
				}
				processed[i][j] = std::to_string(count);
			}
		}
	}

	return processed;
}

int main(){
	int r, c, f=1;
	std::string line;
	vvs field, processedField;

	while(scanf("%d %d", &r, &c) && r!=0 && c!=0){
		if(f>1) std::cout << std::endl;

		clearField(&field);
		clearField(&processedField);
		field = vvs(r, std::vector<std::string>(c));

		for(int i=0; i<r; i++){
			std::cin >> line;
			for(int j=0; j<line.length(); j++){
				field[i][j] = line[j];
			}
		}
		
//		printField(field);
		processedField = getProcessedField(field);
		std::cout << "Field #" << f << ":" << std::endl;
		printField(processedField);
		f++;
	}

	return 0;
}
