#include <cstdio>

int main(){
    int abcde, fghij, used, N, aux = 0;
    int max = 98765, min = 1234;
    while(scanf("%d", &N) != EOF && N > 0){
        if(aux != 0) printf("\n");

        aux = 0;
        for(int i=min; i<=max/N; ++i){
            fghij = i;
            used = fghij < 10000;
            abcde = fghij*N;
            

            while(fghij > 0){
                used |= 1 << fghij%10;
                fghij /= 10;
            }
        
            while(abcde > 0){
                used |= 1 << abcde%10;
                abcde /= 10;
            }
            

            if(used == ((1 << 10)-1)) {
                aux++;
                fghij = i;
                abcde = fghij*N;
                if(abcde < 10000) printf("0");
                printf("%d / ", abcde);
                if(fghij < 10000) printf("0");
                printf("%d = %d\n", fghij, N);
            }
        }

        if(aux == 0) printf("There are no solutions for %d.\n", N);
        aux = 1;
    }

    return 0;
}
