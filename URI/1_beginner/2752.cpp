#include <cstdio>

int main(){
	char buffer[50];
	sprintf(buffer, "AMO FAZER EXERCICIO NO URI");

	printf("<% s>\n", buffer);
	printf("<% 30s>\n", buffer);
	printf("<% .20s>\n", buffer);
	printf("<%-20s>\n", buffer);
	printf("<% -30s>\n", buffer);
	printf("<% .30s>\n", buffer);
	printf("<% 30.20s>\n", buffer);
	printf("<% -30.20s>\n", buffer);

	return 0;
}
