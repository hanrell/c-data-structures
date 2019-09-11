/*****************************************************************
/* Programa para criação de Estrutura de Dados - pilha biencadeada
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 19/08/2019
/******************************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//TIPOS
struct caixa {
	int dado;												      //informação
	struct caixa *prox;
};

//PROTÓTIPOS
void criarPilha(struct caixa**);
int ehvazia (struct caixa**);
void inverter (struct caixa**);
void push (int, struct caixa**);                                      	    // empilhar
int pop (struct caixa**);                                                  // desempilhar


/*################### MAIN ######################*/
void main(){

	struct caixa *pilha;
	char opcao; 											//guarda a opção escolhida pelo usuário.
	int inserir;                                            //guarda o numero a ser inserido.
	
	/*Menu de opções para manipulação da fila*/
	while(1){
		puts("\nO que voce deseja fazer?");
		puts("\tPara criar uma pilha: C");
		puts("\tPara verificar se a pilha esta vazia: V");
		puts("\tPara inserir um elemento na pilha: I");
		puts("\tPara inverter a pilha: B");
		puts("\tPara remover o topo da pilha: R");
		puts("\tPara encerrar aplicacao: S");
		scanf(" %c", &opcao);

		switch (opcao)
		{
			case 'C':
				criarPilha(&pilha);
				break;
			case 'V':
                if (ehvazia(&pilha)) printf("A pilha esta vazia.\n");
                else printf("A pilha nao esta vazia.\n");
                break;
            case 'B':
				inverter(&pilha);
				break;
            case 'I':
                printf("\nDigite o numero a ser inserido: ");
                scanf("%d", &inserir);
                push(inserir, &pilha);
                break;
            case 'R':
            	if (ehvazia(&pilha)) pop(&pilha);
                else printf ("Numero removido da pilha: %d\n",pop(&pilha));
                break;
            case 'S':
                exit(0);
        }

    }
}

/*Função que cria a pilha*/
void criarPilha(struct caixa **pilha){

	*pilha = 0;
	printf("A pilha foi criada.\n");

}

/*Função que verifica se a pilha está vazia*/
int ehvazia (struct caixa **pilha){

    if(!*pilha) return 1;                    						// se pilha for igual a zero, função retorna 1.
    else return 0;
}

/*Função que insere o inteiro 'add' no topo da pilha*/
void push (int add, struct caixa **pilha){

	struct caixa *novo;
	
	novo = (struct caixa*)malloc(sizeof(struct caixa));
	if(!novo){
		printf("A memoria nao pode ser alocada.\n");
        return;
	}
	
	novo->dado = add;
	
	
	if (ehvazia(*&pilha)){
		novo->prox = 0;
	} else {
		novo->prox = *pilha;
	}
	
	*pilha = novo;
	printf("Numero inserido no topo da pilha: %d\n", (*pilha)->dado);

}
/*Função que remove o topo da pilha*/
int pop (struct caixa **pilha){
		
        if (ehvazia(*&pilha)) {
        	printf("Pilha vazia.\n");
        	return 0;
        }
        	
       int removido = (*pilha)->dado;
        
        if (!(*pilha)->prox){
        	*pilha = 0;
       	} else {
       	  	struct caixa *aux = *pilha;
       	  	*pilha = (*pilha)->prox;
       	  	free(aux);
       	}
       	return (removido);
        
}

void inverter (struct caixa **pilha){
	
	if (ehvazia(*&pilha)) {
        	printf("Pilha vazia.\n");
        	return;
        }
        
    struct caixa *invertida;
    criarPilha(&invertida);
    
    while (*pilha){
    	push(pop(*&pilha), &invertida);
    }
    
    *pilha = invertida;
    
    printf("Topo da pilha: %d\n", (*pilha)->dado);
}






