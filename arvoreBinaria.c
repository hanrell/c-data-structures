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

//PROTÓTIPOS

void criarArvore(struct no **);
struct no* inserir(int, struct no*, struct no*);
void mostrarPrefix(struct no*);
void mostrarInfix(struct no*);
void mostrarPosfix(struct no*);
struct no* limpar(struct no *);
void removeFolha(struct no*, struct no**, int);


/**################### MAIN ######################*/
void main(){
    struct no* arvore;
	char opcao; 											//guarda a opção escolhida pelo usu�rio.
	int insercao;                                            //guarda o numero a ser inserido na arvore.

	/*Menu de opções para manipulação da arvore*/
	while(1){
		puts("\nO que voce deseja fazer?");
		puts("\tPara criar uma arvore: C");
		puts("\tPara mostrar a arvore: L");
		puts("\tPara inserir um elemento na arvore: I");
        puts("\tPara remover uma folha da arvore: F");
        puts("\tPara esvaziar a arvore: E");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarArvore(&arvore);
				break;
            case 'L':{
                int choice;
                puts("\nPara mostrar Prefix: 1");
                puts("Para mostrar Infix: 2");
                puts("Para mostrar Posfix: 3");
                scanf(" %d", &choice);
                switch (choice){
                    case 1: mostrarPrefix(arvore); break;
                    case 2: mostrarInfix(arvore); break;
                    case 3: mostrarPosfix(arvore); break;
                }
                break;
            }
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &insercao);
                arvore = inserir(insercao, arvore, 0);
                break;
            case 'F':
                printf("\nDigite o numero a ser removido: ");
                scanf("%d", &insercao);
                removeFolha(arvore, &arvore, insercao);
                break;
            case 'E':
                arvore = limpar(arvore);
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

/** Lista elementos da árvore na forma Infixada*/
void mostrarInfix(struct no *arvore){
    if(!arvore) return;
    mostrarInfix(arvore -> left);
    printf("\n%d", arvore -> dado);
    mostrarInfix(arvore -> right);
}

/** Lista elementos da árvore na forma Posfixada*/
void mostrarPosfix(struct no *arvore){
    if(!arvore) return;
    mostrarPosfix(arvore -> left);
    mostrarPosfix(arvore -> right);
    printf("\n%d", arvore -> dado);
}

/** Lista elementos da árvore na forma Prefixada*/
void mostrarPrefix(struct no *arvore){
    if(!arvore) return;
    printf("\n%d", arvore -> dado);
    mostrarPrefix(arvore -> left);
    mostrarPrefix(arvore -> right);
}

/** Função que esvazia a árvore*/
struct no* limpar (struct no *arvore){
    if(arvore){
    limpar(arvore -> left);
    limpar(arvore -> right);
    free(arvore);
    } else
    return 0;
}

/**Função que remove folha da árvore, se existir*/
void removeFolha(struct no *ant, struct no **arvore, int n){
    struct no *aux = *arvore;
    
    if(!aux) return;                                                        // não achou a folha.

    if(n == aux->dado && !aux->left && !aux->right){                        // se o valor for encontrado e estiver numa folha.
    
        if(aux == ant->right) ant->right = 0;
        else ant->left = 0;

        if(aux == ant) *arvore = 0;                                          // se possuir apenas um nó.

        free(aux);
    } else {                                                                // faz a busca.
        if(n > aux->dado) removeFolha(aux,&(aux->right), n);
        else removeFolha(aux,&(aux->left), n);
    }
}
