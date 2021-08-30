#include <cstdio>
#include <iostream>

int maxAbs(int a, int b){
	int c = a < 0 ? -a : a;
	int d = b < 0 ? -b : b;

	if(c < d) return b;
	return a;
}

int main(){
	int x, vr, vl, s;
	int c[15];
	std::string s1, s2, s3;
	char counter;

	scanf("%d", &x);

	while(x--){
		for(int i=0; i<13; i++) c[i] = -999;

		for(int i=0; i<3; i++){
			std::cin >> s1  >> s2 >> s3;
			if(s3.compare("even") == 0){
				vl = 0;
				vr = 0;
			}else if(s3.compare("down") == 0){
				vl = 1;
				vr = -1;
			}else{
				vl = -1;
				vr = 1;
			}

			int ix, iy;
			for(int j=0; j<s1.length(); j++){
				ix = s1[j]-'A'; 
				iy = s2[j]-'A';
				
				if(vl == 0) c[ix] = vl;
				else if(c[ix] != 0) c[ix] = (c[ix] == -999) ? vl : (c[ix] + vl);
				if(vr == 0) c[iy] = vr;	
				else if(c[iy] != 0) c[iy] = (c[iy] == -999) ? vr : (c[iy] + vr);
			}

		}
		
		s = -1;
		for(int i=0; i<13; i++){
			if(c[i] != -999 && c[i] != 0){
				s = s < 0 ? i : (maxAbs(c[i], c[s]) == c[s] ? s : i);
			}
		}

		counter = s + 'A';	
		std::cout << counter << " is the counterfeit coin and it is " << (c[s] < 0 ? "heavy." : "light.") << std::endl;
	}

	return 0;
}
