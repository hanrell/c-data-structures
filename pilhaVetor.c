/*****************************************************************
/* Programa para criação de Estrutura de Dados - pilha (em vetor)
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 19/08/2019
/******************************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//VARIAVEIS GLOBAIS

/**variáveis da pilha**/
int ldados[MAX];												      //informação
int topo;                                                         //indice do último elemento

//PROTÓTIPOS
void criarPilha(int*);
void inverter (int *, int *);
void push (int, int*, int*);                                      // empilhar
int pop (int*, int*);                                                  // desempilhar


/*################### MAIN ######################*/
void main(){

	char opcao; 											//guarda a opção escolhida pelo usuário.
	int inserir;                                            //guarda o numero a ser inserido.
	while(1){
		puts("O que voce deseja fazer?");
		puts("\tPara criar uma pilha: C");
		puts("\tPara inserir um elemento na pilha: I");
		puts("\tPara inverter a pilha: B");
		puts("\tPara remover o topo da lista: R");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarPilha(&topo);
				break;
			case 'B':
				inverter(&topo, ldados);
				break;
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &inserir);
                push(inserir, ldados,&topo);
                break;
            case 'R':
                printf ("%d\n",pop(&topo, ldados));
                break;
            case 'S':
                exit(0);
        }

    }
}

/*Função que cria a pilha*/
void criarPilha(int *topo){

	*topo = 0;
	printf("A pilha foi criada.\n");

}

/*Função que insere o inteiro 'add' no topo da pilha*/
void push (int add, int *ldados, int *topo){

	if (*topo == MAX){
		printf("Pilha cheia.\n");
		return;
	}

	ldados[*topo] = add;
	*topo = *topo +1;

}
/*Função que remove o topo da pilha*/
int pop (int *topo, int *ldados){

        if (*topo == 0){
        	printf("Pilha vazia.\n");
        	return 0;
        }
        *topo = (*topo) -1;
        return (ldados[*topo]);
}

/*Função que inverte os elementos da pilha*/
void inverter (int *topo, int *ldados){

	if (*topo == 0){
        	printf("Pilha vazia.\n");
        	return;
        }
        
    int ultimo = *topo;
        
    int aux1[MAX];
    int topoaux1 = 0;
    
    int aux2[MAX];
    int topoaux2 = 0;
    
    for (int i = 0; i < ultimo; i++){
		push(pop(*&topo, ldados), aux1, &topoaux1);
	}
	
	for (int i = 0; i < ultimo; i++){
		push(pop(&topoaux1, aux1), aux2, &topoaux2);
	}
	
	for (int i = 0; i < ultimo; i++){
		push(pop(&topoaux2, aux2), ldados, *&topo);
	}
}
