/***************************************************************************
/* Programa para criação de Estrutura de Dados - lista duplamente encadeada
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 30/07/2019
/***************************************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//VARIAVEIS GLOBAIS

//TIPOS

struct caixa {
	int dado;
	struct caixa *prox;
	struct caixa *ant;
};

//PROTÓTIPOS

void criarLista(struct caixa **);
void inserirInicio(struct caixa**, int);
void inverter(struct caixa**);
void listar(struct caixa*);


/**################### MAIN ######################*/
void main(){
    struct caixa* lista;
	char opcao; 											//guarda a opção escolhida pelo usuário.
	int inserir;                                            //guarda o numero a ser inserido na lista.

	/*Menu de opções para manipulação da lista*/
	while(1){
		puts("O que voce deseja fazer?");
		puts("\tPara criar uma lista: C");
		puts("\tPara listar a lista: L");
		puts("\tPara inserir um elemento no começo da lista: I");
		puts("\tPara inverter os elementos da lista: B");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarLista(&lista);
				break;
            case 'L':
                listar(lista);
                break;
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &inserir);
                inserirInicio(&lista, inserir);
                break;
            case 'B':
                inverter(&lista);
                break;
            case 'S':
                exit(0);
			default:
			printf("Comando invalido.\n");
        }

    }
}

/**Função que cria a lista*/
void criarLista(struct caixa **listaLocal){
    *listaLocal = 0;													// a lista começa vazia, logo aponta para o nulo.
}

/**Função que insere um elemento no começo na lista*/
void inserirInicio(struct caixa** listaLocal, int add){

    struct caixa *novo;
    novo = (struct caixa*)malloc(sizeof(struct caixa));					// aloca dinamicamente memória para uma nova variável tipo caixa.
    if (!novo){
        printf("A memoria nao pode ser alocada.\n");					// verifica se a memória foi alocada com sucesso.
        return;
    }

    novo -> dado = add;													// atribui o valor passado pelo usuário ao elemento a ser inserido na lista.

    if (*listaLocal == 0){                                              // se a lista estiver vazia, lista aponta para elemento inserido.
        *listaLocal = novo;
        novo -> ant = 0;
        novo -> prox = 0;
    } else {
        novo -> prox = *listaLocal;                                     // faz o novo elemento apontar para o primeiro da lista (seu próximo).
        novo -> ant = 0;                                                // faz antecessor do novo elemento valer zero (ele é o primeiro).
        (*listaLocal) -> ant = novo;									// faz segundo elemento apontar para o primeiro (o novo).
        *listaLocal = novo;                                             // faz lista apontar para o novo elemento;
    }
}

/**Função que lista todos os elementos da lista*/
void listar(struct caixa *listaLocal){

    if (listaLocal == 0){
        printf("A lista esta vazia.\n");
        return;
    } else {
        struct caixa *aux;
        for (aux = listaLocal; aux; aux = aux -> prox){				// percorre a lista, imprimindo do primeiro elemento até o último.
            printf("%d\n",aux -> dado);
        }
    }
}

/**Função que inverte a ordem dos elementos da lista*/
void inverter(struct caixa **listaLocal){

	if (*listaLocal == 0){
        printf("A lista esta vazia.\n");
        return;	
	}
    struct caixa *aux, *anterior;                                     // variaveis auxiliares.

    for (aux = *listaLocal, anterior = 0; aux; anterior = aux, aux = aux -> ant){
        aux -> ant = aux -> prox;
        aux -> prox = anterior;
    }

    *listaLocal = anterior;
}
