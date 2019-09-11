/**************************************************************
/* Programa para criação de Estrutura de Dados - árvore binária
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 09/09/2019
/**************************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//VARIAVEIS GLOBAIS

//TIPOS

struct no {
	int dado;
	struct no *left;
	struct no *right;
};

//PROT�TIPOS

void criarArvore(struct no **);
struct no* inserir(int, struct no*, struct no*);
//void listar(struct no*);


/**################### MAIN ######################*/
void main(){
    struct no* arvore;
	char opcao; 											//guarda a opção escolhida pelo usu�rio.
	int insercao;                                            //guarda o numero a ser inserido na arvore.

	/*Menu de op��es para manipulação da arvore*/
	while(1){
		puts("O que voce deseja fazer?");
		puts("\tPara criar uma arvore: C");
		//puts("\tPara listarr a arvore: L");
		puts("\tPara inserir um elemento na arvore: I");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarArvore(&arvore);
				break;
            /*case 'L':
                listar(arvore);
                break;*/
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &insercao);
                arvore = inserir(insercao, arvore, 0);
                break;
            case 'S':
                exit(0);
			default:
			printf("Comando invalido.\n");
        }

    }
}

/**Função que cria a arvore*/
void criarArvore(struct no **arvore){
    *arvore = 0;													// a arvore começa vazia, logo aponta para o nulo.
}

/**Fun��o que insere um elemento no come�o na arvore*/
struct no* inserir(int add, struct no* i, struct no* ii){

    if(i){
        if(i -> dado > add){
            i -> left = inserir(add, i -> left, 0);
            printf ("\n%d\n", i -> dado);
        } else {
            i -> right = inserir(add, i -> right, 0);
            printf ("\n%d\n", i -> dado);
        }
        return i;
    } else {
        struct no *novo;
        novo = (struct no*)malloc(sizeof(struct no));					// aloca dinamicamente mem�ria para uma nova vari�vel tipo no.
        if (!novo){
            printf("A memoria nao pode ser alocada.\n");					// verifica se a mem�ria foi alocada com sucesso.
            return;
        }

        novo -> dado = add;
        novo -> left = 0;
        novo -> right = 0;

        return novo;
    }
    
}
