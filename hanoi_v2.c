#include <stdio.h>
#include <stdlib.h>
struct disco discos;
struct disco **torres;
int total;

struct disco{
    int tamanho;
    int posicao;
    int torre;
};

int main(){
   
    int *torre;
    int i;
    printf("Digite o número de discos:");
    scanf("%d",&discos);
    total = discos;
    torres = malloc(3*sizeof(*discos));
    for(i = 0;i<3;i++){
        torres[i] = malloc(discos*sizeof(int));
    }
    for(i = discos; i > 0; i--){
    }
   // hanoi(discos,torres,total);

}