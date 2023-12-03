#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct disco discos;
int total;
struct disco *t_discos;
struct disco{
    int tamanho;
    int torre;
};
void inserir(int total,int torreIn,int torreFi){
    int i;
    for (i = total;i >= 0; i--){
        if(t_discos[i].torre == torreIn){
            t_discos[i].torre = torreFi;
            break;
        }
    }
}
int main(){
    int i,j;
    printf("Digite o número de discos:");
    scanf("%d",&total);
    t_discos = malloc(total*(sizeof(struct disco)));
    for(i = total-1; i >= 0; i--){
        t_discos[i].tamanho = total-i;
        t_discos[i].torre = 0;
    }
    for(i = total-1; i >= 0; i--){
    printf("disco %d torre %d\n",t_discos[i].tamanho,t_discos[i].torre);
    }
    for(i = 1; i < pow(2,total); i++){
        if(total % 2 == 1){
        if(i % 3 == 1){
            inserir(total,0,2);
        }
        if(i % 3 == 2){
            inserir(total,0,1);
        }
        if(i % 3 == 0){
            inserir(total,2,1);
        }
        }
        if(total % 2 == 0){
        if(i % 3 == 1){
            inserir(total,0,2);
        }
        if(i % 3 == 2){
            inserir(total,0,1);
        }
        if(i % 3 == 0){
            inserir(total,1,2);
        }
        }
    }
    for(i = total-1; i >= 0; i--){
    printf("disco %d torre %d\n",t_discos[i].tamanho,t_discos[i].torre);
    }
}
