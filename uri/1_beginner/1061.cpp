#include <iostream>
#include <cstdio>

int main(){

	int d1, h1, m1, s1, d2, h2, m2, s2;
	scanf("Dia %d\n", &d1);
	scanf("%d : %d : %d\n", &h1, &m1, &s1);
	scanf("Dia %d\n", &d2);
	scanf("%d : %d : %d\n", &h2, &m2, &s2);
	
	int seconds1 = s1 + m1*60 + h1*3600 + d1*24*3600;
	int seconds2 = s2 + m2*60 + h2*3600 + d2*24*3600;
	int duration = seconds2 - seconds1;

	int d = 0, h = 0, m = 0, s = 0;
	s = duration%60;
	m = duration/60;
	h = m/60;
	d = h/24;

	m = m%60;
	h = h%24;

	std::cout << d << " dia(s)" << std::endl;
	std::cout << h << " hora(s)" << std::endl;
	std::cout << m << " minuto(s)" << std::endl;
	std::cout << s << " segundo(s)" << std::endl;

	return 0;
}
