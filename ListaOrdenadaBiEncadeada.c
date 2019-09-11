/**************************************************************************************
/* Programa para criação de Estrutura de Dados - lista duplamente encadeada e ordenada
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 30/07/2019
/**************************************************************************************/

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
void inserir(struct caixa**, int);
void inverter(struct caixa**);
void listar(struct caixa*);
void remover(struct caixa**, int);
void concatenar (struct caixa**, struct caixa**);


/**################### MAIN ######################*/
void main(){
    struct caixa* lista;
	char opcao; 											//guarda a opção escolhida pelo usuário.
	int dado;                                              //guarda o numero a ser inserido na lista.
	
	
	struct caixa* lista2;
	criarLista(&lista2);
	
	for (int i = 1; i <=3; i++) inserir(&lista2, i);
	
	listar(lista2);
	

	/*Menu de opções para manipulação da lista*/
	while(1){
		puts("\nO que voce deseja fazer?");
		puts("\tPara criar uma lista: C");
		puts("\tPara listar a lista: L");
		puts("\tPara inserir um elemento na lista: I");
		puts("\tPara remover um elemento da lista: R");
		puts("\tPara inverter os elementos da lista: B");
		puts("\tPara concatenar os elementos da lista: F");
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
                scanf("%d", &dado);
                inserir(&lista, dado);
                break;
            case 'B':
                inverter(&lista);
                break;
            case 'F':
                concatenar(&lista, &lista2);
                break;
            case 'R':
                printf("\nDigite o numero a ser removido: ");
                scanf("%d", &dado);
                remover(&lista, dado);
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

/**Função que insere um elemento na lista ordenada*/
void inserir(struct caixa** listaLocal, int add){

    struct caixa *novo;
    novo = (struct caixa*)malloc(sizeof(struct caixa));					// aloca dinamicamente memória para uma nova variável tipo caixa.
    if (!novo){
        printf("A memoria nao pode ser alocada.\n");					// verifica se a memória foi alocada com sucesso.
        return;
    }

    novo -> dado = add;													// atribui o valor passado pelo usuário ao elemento a ser inserido na lista.

    if (*listaLocal == 0){                                              // se a lista estiver vazia, o elemento inserido será o primeiro.
        novo -> ant = 0;
        novo -> prox = 0;
        *listaLocal = novo;
    } else {

        struct caixa *aux, *anterior;

        for (aux = *listaLocal, anterior = 0; aux && aux -> dado < add; anterior = aux, aux = aux -> prox);         // para no elemento ligeiramente maior do que o que vai ser inserido.
        if (aux == 0){                                                                                              // essa condição verifica se o número a ser inserido é o maior de todos.
            novo -> prox = 0;
            novo -> ant = anterior;
            anterior -> prox = novo;
        } else if (aux == *listaLocal){                                                                             // essa condição verifica se o número a ser inserido é o menor de todos.
            novo -> ant = 0;
            novo -> prox = aux;
            aux -> ant = novo;
            *listaLocal = novo;
        } else {                                                                                                    // esse else insere o valor na posição correta em meio a lista.
            novo -> prox = aux;
            novo -> ant = aux -> ant;
            aux -> ant -> prox = novo;
            aux -> ant = novo;
        }
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
    struct caixa *aux, *anterior;                                     // variaveis auxiliares.

    for (aux = *listaLocal, anterior = 0; aux; anterior = aux, aux = aux -> ant){
        aux -> ant = aux -> prox;
        aux -> prox = anterior;
    }

    *listaLocal = anterior;
}

/**Função que remove um elemento 'dado' na lista ordenada*/
void remover (struct caixa **listaLocal, int dado){

    if (*listaLocal == 0){
        printf("A lista esta vazia.\n");
        return;
    }

    struct caixa *aux;

    for (aux = *listaLocal; aux && aux -> dado != dado; aux = aux -> prox);

    if (aux == 0) return;
    else if (aux == *listaLocal){
        *listaLocal = aux -> prox;
        if (aux -> prox) aux -> prox -> ant = 0;
        free(aux);
    } else {
        aux -> ant -> prox = aux -> prox;
        if (aux -> prox) aux -> prox -> ant = aux -> ant;
        free (aux);
    }
}

void concatenar (struct caixa **lista1, struct caixa **lista2){

	struct caixa *aux;
	
	for (aux = *lista2; aux; aux = aux -> prox){
		inserir(*&lista1, aux->dado);
	}

}
