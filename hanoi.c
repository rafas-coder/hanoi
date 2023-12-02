#include <stdio.h>
#include <stdlib.h>
int discos;
int **torres;
int total;
void inserir(int disco,int* torreIn, int* torreFi){
    int i,j;
    for(i =0;i<discos;i++){
        if (torreIn[i] == disco){
            for(j = 0; j<discos;j++){
                if (torreFi[j] == 0){
                    torreFi[j] = disco;
                    torreIn[i] = 0;
                    break;
                }
            }
        }
    }
}

int procurarDisco(int disco, int** torres){
    int i, j;
    for(i=0;i<3;i++){
        for(j = 0; j < discos;j++){
            if(torres[i][j] == disco){
                return i;
            }
        }
    }
}
void hanoi(int discos, int** torres,int total){
    if(discos == 2 && total % 2 == 1){
        inserir(1, torres[procurarDisco(1,torres)],torres[(procurarDisco(1,torres)+2)%3]);
        inserir(2,torres[procurarDisco(2,torres)],torres[(procurarDisco(2,torres)+1)%3]);
        inserir(1, torres[procurarDisco(1,torres)],torres[(procurarDisco(1,torres)+2)%3]);
    }
    if(discos == 2 && total % 2 == 0){
        inserir(1, torres[procurarDisco(1,torres)],torres[((procurarDisco(1,torres)+1))%3]);
        inserir(2,torres[procurarDisco(2,torres)],torres[(procurarDisco(2,torres)+2)%3]);
        inserir(1, torres[procurarDisco(1,torres)],torres[((procurarDisco(1,torres)+1))%3]);
    }
    if(discos != total && total % 2 == 1 && discos != 2 && discos % 2 == 1){
        hanoi(discos-1,torres,total);
        inserir(discos, torres[procurarDisco(discos,torres)],torres[(procurarDisco(discos,torres)+2)%3]);
        hanoi(discos-1,torres,total);
    }
    if(discos != total && total % 2 == 1 && discos != 2 && discos % 2 == 0){
        hanoi(discos-1,torres,total);
        inserir(discos, torres[procurarDisco(discos,torres)],torres[(procurarDisco(discos,torres)+1)%3]);
        hanoi(discos-1,torres,total);
    }
    if(discos != total && total % 2 == 0 && discos != 2 && discos % 2 == 1){
        hanoi(discos-1,torres,total);
        inserir(discos, torres[procurarDisco(discos,torres)],torres[(procurarDisco(discos,torres)+1)%3]);
        hanoi(discos-1,torres,total);
    }
    if(discos != total && total % 2 == 0 && discos != 2 && discos % 2 == 0){
        hanoi(discos-1,torres,total);
        inserir(discos, torres[procurarDisco(discos,torres)],torres[(procurarDisco(discos,torres)+2)%3]);
        hanoi(discos-1,torres,total);
    }
    if(discos == total && total != 2){
        hanoi(discos-1,torres,total);
        inserir(discos, torres[procurarDisco(discos,torres)],torres[(procurarDisco(discos,torres)+2)%3]);
        hanoi(discos-1,torres,total);
    }

}
int main(){
   
    int *torre;
    int i;
    printf("Digite o número de discos:");
    scanf("%d",&discos);
    total = discos;
    torres = malloc(3*sizeof(int*));
    for(i = 0;i<3;i++){
        torres[i] = malloc(discos*sizeof(int));
    }
    for(i = discos; i > 0; i--){
        torres[0][discos-i] = i; 
    }
    hanoi(discos,torres,total);

   for(i = 0; i <= discos; i++){
        printf("Torre 1 %d\t Torre 2 %d\t Torre 3 %d\t\n",torres[0][discos - i],torres[1][discos - i],torres[2][discos - i]);
    }
}
