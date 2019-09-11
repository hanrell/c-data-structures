/*****************************************************
/* Programa para criação de Estrutura de Dados - fila
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 15/08/2019
/*****************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//VARIAVEIS GLOBAIS

//TIPOS

struct caixa {
	int dado;
	struct caixa *prox;
};

struct fila {
	struct caixa *inicio;
	struct caixa *fim;
};

//PROTÓTIPOS
void criarFila(struct fila*);
void concatenar (struct fila*, struct fila*);
int ehvazia (struct fila);
void inserirFim (int, struct fila*);
void removerInicio (struct fila*);


/*################### MAIN ######################*/
void main(){

    //struct caixa* lista;
    struct fila f;											// apontador para inicio e fim da fila.
    struct fila g;

	char opcao; 											//guarda a opção escolhida pelo usuário.
	int inserir;                                            //guarda o numero a ser inserido na fila.

	criarFila(&g);

	for(int i = 1; i <=3; i++) inserirFim(i, &g);

	/*Menu de opções para manipulação da fila*/
	while(1){
		puts("\nO que voce deseja fazer?");
		puts("\tPara criar uma fila: C");
		puts("\tPara verificar se a fila esta vazia: V");
		puts("\tPara inserir um elemento na fila: I");
		puts("\tPara remover um elemento da fila: R");
		puts("\tPara concatenar com fila g: T");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarFila(&f);
				printf("A fila foi criada.\n");
				break;
			case 'V':
                if (ehvazia(f)) printf("A fila esta vazia.\n");
                else printf("A fila nao esta vazia.\n");
                break;
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &inserir);
                inserirFim(inserir, &f);
                break;
            case 'R':
                removerInicio(&f);
                break;
            case 'T':
                concatenar(&f,&g);
                printf("Começo f: %d\nFim f: %d\n", f.inicio->dado, f.fim->dado);
                break;
            case 'S':
                exit(0);
			default:
			printf("Comando invalido.\n");
        }

    }
}

/*Função que cria a fila*/
void criarFila(struct fila *f){
    f->inicio = 0;													// a fila começa vazia, logo aponta para o nulo.
    f->fim = 0;
}

/*Função que verifica se a fila está vazia*/
int ehvazia (struct fila f){

    if(!f.inicio && !f.fim) return 1;                    						// se fila for igual a zero, função retorna 1.
    else return 0;
}

/*Função que insere o inteiro 'add' no fim da fila*/
void inserirFim (int add, struct fila *f){

	struct caixa *novo;
	novo = (struct caixa*)malloc(sizeof(struct caixa));					// aloca dinamicamente memória para uma nova variável tipo caixa.
		if (!novo){
        	printf("A memoria nao pode ser alocada.\n");
        	return;
    	}

    novo->dado = add;
	novo->prox = 0;

	if (ehvazia(*f)){
		f->inicio = novo;

    } else{
		f->fim -> prox = novo;
	}
	f->fim = novo;
	printf ("Começo da fila %d\n", f->inicio->dado);
	printf ("Fim da fila %d\n", f->fim->dado);
}


/*Função que remove o primeiro elemento da fila*/
void removerInicio (struct fila *f){

	if (ehvazia(*f)){
        printf("A fila esta vazia.\n");
        return;
    }

    struct caixa *aux;
    aux = f->inicio;

    f->inicio = f->inicio -> prox;
	printf ("Removido da fila %d\n", aux -> dado);
    free(aux);

    if(!f->inicio){
		f->fim = 0;									//se o primeiro elemento é zero, significa que a fila está vazia, então temos que fazer o fim apontar para 0.
		printf ("Começo da fila %d\n", f->inicio);
		printf ("Fim da fila %d\n", f->fim);
	return;
	}

    printf ("Começo da fila %d\n", f->inicio->dado);
	printf ("Fim da fila %d\n", f->fim->dado);
}

void concatenar (struct fila *f, struct fila *g){

    struct fila aux;
    criarFila(&aux);

    while (f->fim && g->fim){
        if (f->fim){
            inserirFim(f->inicio->dado, &aux);
            removerInicio(*&f);
        }
        if (g->fim){
            inserirFim(g->inicio->dado, &aux);
            removerInicio(*&g);
        }
    }
    *f = aux;
}
