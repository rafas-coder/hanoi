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
    //O caso base são os dois primeiros discos, que são movidos de acordo com seguinte lógica
    //Se o total de discos for par, o disco 1 moverá duas torres, enquanto o disco 2 moverá
    //apenas uma vez,já quando o total de discos é impar, o oposto ocorre
    if(discos == 2){
        inserir(1, torres[procurarDisco(1,torres)],torres[(procurarDisco(1,torres)+1+(total % 2))%3]);
        inserir(2,torres[procurarDisco(2,torres)],torres[(procurarDisco(2,torres)+2-(total % 2))%3]);
        inserir(1, torres[procurarDisco(1,torres)],torres[(procurarDisco(1,torres)+1+(total % 2))%3]);
    }
    //Para o caso geral,ocorre uma chamada recusiva para uma versão reduzida do problema,depois ocorre 
    //uma inserção que obedece a seguinte lógica, caso total e o disco atual forem pares ou impares,
    //o disco moverá duas torres,caso contrário moverá apenas uma torre,depois haberá uma outra chamada recursiva
    //para finalizar a torre intermediaria ou final
    if(discos != 2){
        hanoi(discos-1,torres,total);
        inserir(discos, torres[procurarDisco(discos,torres)],torres[(procurarDisco(discos,torres)+1+(total % 2 == discos % 2))%3]);
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

}
