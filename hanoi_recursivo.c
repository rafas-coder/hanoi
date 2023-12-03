#include <stdio.h>
#include <stdlib.h>
//Essas são as variaveis globais que são acessadas por todas
//as funções
int total;
int discos;
int **torres;
int *torre;
int i;

//Essa função vasculha em todas as torres em busca do disco alvo
//e retorna em qual torre ele foi encontrado
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
//A função inserir recebe o disco que será transferido, e as torre inicio e destino
//inicialmente o algoritmo procura o disco na torre inicial e transfere para a 
//primeira região livre na torre destino,além disso, essa é a função que indica
//para o usuário qual disco ele deve mover e para qual torre
void inserir(int disco,int* torreIn, int* torreFi){
    int i,j;
    for(i =0;i<discos;i++){
        if (torreIn[i] == disco){
            for(j = 0; j<discos;j++){
                if (torreFi[j] == 0){
                    printf("Mova o disco %d da pilha %c",disco,(procurarDisco(disco,torres))%3+65);
                    torreFi[j] = disco;
                    torreIn[i] = 0;
                    printf(" para a pilha %c\n",(procurarDisco(disco,torres))%3+65);
                    break;
                }
            }
        };
    }
}

//A função seguinte resolve a torre de hanoi de forma recursiva de acordo com o número de discos
void hanoi(int discos, int** torres,int total){
    //Tanto o caso base quanto o geral faz uso das mesmas linhas de código, a diferença que o disco um
    //não executa a chamada recursiva,dessa maneira o código tem a seguinte lógica,para montar a torre
    //final na pilha C, ele monta uma torre intermediaria na pilha B, e para montar a torre intermediária
    //na pilha B, ele monta uma torre interdiária na pilha C, e assim sucessivamente,no código isso se 
    //demonstra da seguinte forma,quando o disco a ser movido é par e o total de discos também é par,
    //ele move apenas uma torre, e quando o disco atual é impar, ele move duas torres,quando o total
    //de discos é par o inverso acontece,por fim, a outra chamada recursiva desloca a torre interdiária
    //para torre maior ou a torre final.
        if(discos != 1){
        hanoi(discos-1,torres,total);
        }
        inserir(discos, torres[procurarDisco(discos,torres)],torres[(procurarDisco(discos,torres)+2-(total % 2 != discos % 2))%3]);
        if(discos != 1){
        hanoi(discos-1,torres,total);
        }
}
//A main faz a impressão dos primeiros caracteres, como também recebe o input
//do usuário e para finalizar a alocação de memória e primeira chamada da 
//função hanoi
int main(){
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
