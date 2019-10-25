#include <iostream>
#include <cstdio>
#include <map>

int main(){
	std::map<int, std::string> ddd;
	ddd[61] = "Brasilia"; ddd[71] = "Salvador"; ddd[11] = "Sao Paulo"; 
	ddd[21] = "Rio de Janeiro"; ddd[32] = "Juiz de Fora"; ddd[19] = "Campinas"; 
	ddd[27] = "Vitoria"; ddd[31] = "Belo Horizonte";

	int n;
	scanf("%d", &n);

	if(ddd.find(n) != ddd.end()){
		printf("%s\n", ddd[n].c_str());
	}else{
		printf("DDD nao cadastrado\n");
	}
	return 0;
}
