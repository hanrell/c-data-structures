/****************************************************************
/* Programa para criação de Estrutura de Dados - lista encadeada
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 15/07/2019
/***************************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//VARIAVEIS GLOBAIS

//TIPOS

struct caixa {
	int dado;
	struct caixa *prox;
};

//PROTÓTIPOS
void criarLista(struct caixa**);
int ehvazia (struct caixa**);
void esvaziar(struct caixa**);
void listar(struct caixa*);
void inserirInicio (int, struct caixa**);
void inserirFim (int, struct caixa**);
void removerFim (struct caixa**);
void removerInicio (struct caixa**);
struct caixa* inverter (struct caixa*);
struct caixa* separar (struct caixa**);


/*################### MAIN ######################*/
void main(){

    struct caixa* lista;
	char opcao; 											//guarda a opção escolhida pelo usuário.
	int inserir;                                            //guarda o numero a ser inserido na lista.
	
	/*Menu de opções para manipulação da lista*/
	while(1){
		puts("O que voce deseja fazer?");
		puts("\tPara criar uma lista: C");
		puts("\tPara verificar se a lista esta vazia: V");
		puts("\tPara esvaziar a lista: E");
		puts("\tPara listar a lista: L");
		puts("\tPara inserir um elemento no começo da lista: I");
		puts("\tPara inserir um elemento no fim da lista: F");
		puts("\tPara remover um elemento do fim da lista: R");
		puts("\tPara remover um elemento do começo da lista: A");
		puts("\tPara inverter os elementos da lista: B");
		puts("\tPara separar a lista em pares e ímpares: P");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarLista(&lista);
				printf("A lista foi criada.\n");
				break;
			case 'V':
                if (ehvazia(&lista)) printf("A lista esta vazia.\n");
                else printf("A lista nao esta vazia.\n");
                break;
            case 'E':
                esvaziar(&lista);
                break;
            case 'L':
                listar(lista);
                break;
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &inserir);
                inserirInicio(inserir, &lista);
                break;
            case 'F':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &inserir);
                inserirFim(inserir, &lista);
                break;
            case 'R':
                removerFim(&lista);
                break;
            case 'A':
                removerInicio(&lista);
                break;
            case 'B':
                lista = inverter(lista);
                break;
            case 'P':
                separar(&lista);
                break;
            case 'S':
                exit(0);
			default:
			printf("Comando invalido.\n");
        }

    }
}

/*Função que cria a lista*/ 
void criarLista(struct caixa **listaLocal){
    *listaLocal = 0;													// a lista começa vazia, logo aponta para o nulo.
}

/*Função que verifica se a lista está vazia*/
int ehvazia (struct caixa **listaLocal){

    if(!*listaLocal) return 1;                    						// se lista for igual a zero, função retorna 1.
    else return 0;
}

/*Função que esvazia a lista*/
void esvaziar(struct caixa **listaLocal){

    if (ehvazia(*&listaLocal)){											//verifica se a lista já está vazia.
        printf("A lista esta vazia.\n");		
        return;
    }else{
        struct caixa *aux;
        for (aux = *listaLocal; aux; aux = *listaLocal){				//percorre a lista, apagando do primeiro elemento até o último.
            *listaLocal = aux -> prox;
            free(aux);
        }
		printf("A lista foi esvaziada.\n");
    }
}

/*Função que imprime todos os elementos da lista*/
void listar(struct caixa *listaLocal){

    if (ehvazia(&listaLocal)){
        printf("A lista esta vazia.\n");
        return;
    } else {
        struct caixa *aux;
        for (aux = listaLocal; aux; aux = aux -> prox){				// percorre a lista, imprimindo do primeiro elemento até o último.
            printf("%d\n",aux -> dado);
        }
    }
}

/*Função que insere o inteiro 'add' no início da lista*/
void inserirInicio (int add, struct caixa **listaLocal){

    struct caixa *aux;
    aux = (struct caixa*)malloc(sizeof(struct caixa));					// aloca dinamicamente memória para uma nova variável tipo caixa.
    if (!aux){
        printf("A memoria nao pode ser alocada.\n");					// verifica se a memória foi alocada com sucesso.
        return;
    }
    aux -> dado = add;													// atribui o valor passado pelo usuário ao elemento a ser inserido
    aux -> prox = *listaLocal; 											// na lista.
    *listaLocal = aux;

}

/*Função que insere o inteiro 'add' no fim da lista*/
void inserirFim (int add, struct caixa **listaLocal){
	
	struct caixa *novo;
	novo = (struct caixa*)malloc(sizeof(struct caixa));					// aloca dinamicamente memória para uma nova variável tipo caixa.
		if (!novo){
        	printf("A memoria nao pode ser alocada.\n");
        	return;
    	}
	if (ehvazia(*&listaLocal)){											// se a lista for vazia, a primeira posição já é seu fim, então não
		novo->dado = add;												// é necessário percorrê-la.
		novo->prox = 0;
		*listaLocal = novo;
	
    } else{
		struct caixa *aux;
		for (aux = *listaLocal; aux->prox!=0; aux = aux -> prox); 		// aqui é necessário percorrê-la.
		novo->dado = add;
		novo->prox = 0;
		aux->prox = novo;
	}
}
/*Função que remove o último elemento da lista*/
void removerFim (struct caixa **listaLocal){

	if (ehvazia(*&listaLocal)){
        printf("A lista esta vazia.\n");
        return;
    }
        
    struct caixa *aux, *anterior;

	/*laço for responsável por percorrer a lista até o fim e guardar uma referência para seu penúltimo elemento (que virar a ser o ultimo).*/
    for (aux = *listaLocal; aux->prox!=0; anterior = aux, aux = aux -> prox);
    
    if (aux == *listaLocal) *listaLocal = 0;
    else anterior -> prox = 0;										// o penúltimo elemento se torna o último.
    
    free (aux);
}

/*Função que remove o primeiro elemento da lista*/
void removerInicio (struct caixa **listaLocal){

	if (ehvazia(*&listaLocal)){
        printf("A lista esta vazia.\n");
        return;
    }
        
    struct caixa *aux;
    aux = *listaLocal;
    *listaLocal = aux -> prox;
    free(aux);
}

struct caixa* inverter (struct caixa *listaLocal){

	struct caixa *newLista, *aux;

	criarLista(&newLista);
	
	for (aux = listaLocal; aux; aux = aux -> prox){
	
		inserirInicio(aux -> dado, &newLista);
		
	}
	
	return newLista;
}
	
struct caixa* separar (struct caixa **listaLocal){

	struct caixa *listaPar, *listaImpar, *aux;

	criarLista(&listaPar);
	criarLista(&listaImpar);

	for (aux = *listaLocal; aux; aux = aux -> prox){
		if ((aux -> dado %2) == 0){
			
			inserirFim(aux -> dado, &listaPar);
		} else {
			inserirFim(aux -> dado, &listaImpar);
		}
	}
	*listaLocal = listaImpar;
	free(aux);
	return listaPar;
}
