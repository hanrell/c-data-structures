/***************************************************************
/* Programa para criação de Estrutura de Dados - fila circular
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 02/07/2019
/***************************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//VARIAVEIS GLOBAIS

//TIPOS
/**variáveis da fila**/
struct fila {
    int dados[MAX];												    // informação
    int inicio;                                                     // marcador do inicio da fila
    int fim;                                                        // marcador do fim da fila
};

//PROTÓTIPOS
void criarFila(struct fila*);
void inserirFim (int, struct fila*);
void remover (struct fila*);


/*################### MAIN ######################*/
void main(){

    struct fila fila;
	char opcao; 											//guarda a opção escolhida pelo usuário.
	int inserir;                                            //guarda o numero a ser inserido.
	while(1){
		puts("O que voce deseja fazer?");
		puts("\tPara criar uma fila: C");
		puts("\tPara inserir um elemento na fila: I");
		puts("\tPara remover um elemento da fila: R");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarFila(&fila);
				break;
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &inserir);
                inserirFim(inserir, &fila);
                break;
            case 'R':
                remover(&fila);
                break;
            case 'S':
                exit(0);
            default:
                printf("\nComando inválido\n");
                break;
        }

    }
}

/*Função que cria a fila*/
void criarFila(struct fila *fila){

	fila->inicio = 0;
	fila->fim = 0;
	printf("A fila foi criada.\n");

}

/*Função que insere o inteiro 'add' no fim da fila*/
void inserirFim (int add, struct fila *fila){

    if (fila->fim == fila->inicio){
        printf("Fila cheia.\n");
        return;
    }
    
    if (fila->fim == -1) fila->fim++;

	fila->dados[fila->fim] = add;                                         // adiciona o dado no fim da fila.
	printf("Número inserido no fim da fila: %d\n", fila->dados[fila->fim]);
	fila->fim++;                                                             // incrementa o apontador do fim da fila.
	if(fila->fim == MAX) fila->fim = -1;                                   // se o fim da fila já era o ultimo indice do vetor, agora ele será o primeiro.

}
/*Função que remove o primeiro elemento da fila*/
void remover (struct fila *fila){

	if(fila->inicio == MAX) fila->inicio = 0;

    if(fila->inicio == fila->fim){
        printf("A fila esta vazia.\n");
        return;
	}
	
	int removido = fila->dados[fila->inicio];

    fila->inicio++;

    printf("Número removido da fila: %d\n", removido);
    
}
