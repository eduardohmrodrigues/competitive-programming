#include <cstdio>
#include <vector>
#include <iostream>
#include <math.h>
#include <sstream>

#define PI 3.14159265

struct vec3{
	int x;
	int y;
	int z;

	std::string tostring(){
		std::stringstream ss;
		
		ss << "{ " << x << ", " << y << ", " << z << "} ";
		return ss.str();
	}
};

vec3 rotate(vec3 axis, vec3 vec){
	vec3 out{.x=0, .y=0, .z=0};

	if(axis.x != 0){
		double s = sin(axis.x*PI/2);
		double c = cos(axis.x*PI/2);
		
		out.x = vec.x;
		out.y = c*vec.y + s*vec.z;
		out.z = -s*vec.y + c*vec.z;
	}else if(axis.y != 0){
		double s = sin(axis.y*PI/2);
		double c = cos(axis.y*PI/2);
		
		out.x = c*vec.x - s*vec.z;
		out.y = vec.y;
		out.z = s*vec.x + c*vec.z;
	}else{
		double s = sin(axis.z*PI/2);
		double c = cos(axis.z*PI/2);
		
		out.x = c*vec.x + s*vec.y;
		out.y = -s*vec.x + c*vec.y;
		out.z = vec.z;
	}

	return out;
}

int main(){
	int l, x, y, z;
	std::string bend;
	std::vector<vec3> bends;
	
	while(scanf("%d", &l) && l != 0){
		bends.clear();
		bends.resize(l+1);
		bends[0] = vec3{.x = 1, .y=0, .z=0};

		for(int i=l; i>1; i--){
			std::cin >> bend;
			x = 0; y = 0; z = 0;	
			if(bend.compare("+y") == 0){
				z = -1;
			}else if(bend.compare("-y") == 0){
				z = 1;
			}else if(bend.compare("+z") == 0){
				y = 1;
			}else if(bend.compare("-z") == 0){
				y = -1;
			}
			
			bends[i] = vec3{.x = x, .y=y, .z=z};
		}
		
		std::vector<vec3> mat(3);
		mat[0] = vec3{.x=1, .y=0, .z=0};
		mat[1] = vec3{.x=0, .y=1, .z=0};
		mat[2] = vec3{.x=0, .y=0, .z=1};

		for(int i=2; i<=l; i++){
			if(bends[i].y == 0 && bends[i].z == 0){
//				std::cout << "Vou ignorar o " << i << " bend " << bends[i].tostring() << std::endl;
				 continue;
			}
/*			
			std::cout << "Vou rotacionar no eixo " << i << " bend " << bends[i].tostring() << std::endl;
			
			std::cout << "A mat eh: " << std::endl << "    " << mat[0].tostring() << std::endl;
			std::cout << "    " << mat[1].tostring() << std::endl;
			std::cout << "    " << mat[2].tostring() << std::endl;
			std::cout << "==================" << std::endl;
*/
			if(bends[i].y != 0){
				mat[0] = rotate(vec3{.x=bends[i].y*mat[1].x, .y=bends[i].y*mat[1].y, .z=bends[i].y*mat[1].z}, mat[0]);
				mat[2] = rotate(vec3{.x=bends[i].y*mat[1].x, .y=bends[i].y*mat[1].y, .z=bends[i].y*mat[1].z}, mat[2]);
			}else{
				mat[0] = rotate(vec3{.x=bends[i].z*mat[2].x, .y=bends[i].z*mat[2].y, .z=bends[i].z*mat[2].z}, mat[0]);
				mat[1] = rotate(vec3{.x=bends[i].z*mat[2].x, .y=bends[i].z*mat[2].y, .z=bends[i].z*mat[2].z}, mat[1]);
			}
			//mat[0] = rotate(bends[i], mat[0]);
			//mat[1] = rotate(bends[i], mat[1]);
			//mat[2] = rotate(bends[i], mat[2]);
/*			
			std::cout << "A mat output: " << std::endl << "    " << mat[0].tostring() << std::endl;
			std::cout << "    " << mat[1].tostring() << std::endl;
			std::cout << "    " << mat[2].tostring() << std::endl;
			std::cout << "                  " << std::endl;
			std::cout << "==================" << std::endl;
			std::cout << "                  " << std::endl;
*/
			//if(bends[i].y != 0){
			//}else if(bends[i].z != 0){
			//}
		}

		if(mat[0].x == 1){
			printf("+x\n");
		}else if(mat[0].x == -1){
			printf("-x\n");
		}else if(mat[0].y == 1){
			printf("+y\n");
		}else if(mat[0].y == -1){
			printf("-y\n");
		}else if(mat[0].z == 1){
			printf("+z\n");
		}else{
			printf("-z\n");
		}
	}
	return 0;
}
