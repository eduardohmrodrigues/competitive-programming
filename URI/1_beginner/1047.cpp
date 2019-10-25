#include <iostream>
#include <cstdio>

int main(){
	int a, b, c, d, tm, eh, na;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(a != c || b > d)
	{
		tm = (60 - b) + d;
		na = a+1;	
	}else{
		tm = d - b;
		na = a;
	}

	if(tm >= 60){
		eh = 1;
		tm -= 60;
	}else{
		eh = 0;
	}
	
	if(a > c || (a == c && b >= d)){
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (24-na)+c+eh, tm);
	}else{
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (c-na)+eh, tm);
	}

	return 0;
}
