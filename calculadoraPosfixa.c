/*****************************************************************
/* Programa para criação de Calculadora Pósfixa - pilha (em vetor)
/* Author: Hanrell Ramon Ribeiro de Souza
/* Last update: 18/08/2019
/*****************************************************************/

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//VARIAVEIS GLOBAIS

/**variáveis da pilha**/
float ldados[30];												      //informação
int topo;                                                             //indice do último elemento

//PROTÓTIPOS
void criarPilha(int*);
void push (float, float*, int*);                                      // empilhar
float pop (int*, float*);                                             // desempilhar
float operacao(float, float, char);

/*################### MAIN ######################*/
void main(){

	char operador; 											   //guarda a opção escolhida pelo usuário.
	float operando;                                            //guarda o numero a ser inserido.

    while (1){
        criarPilha(&topo);

        puts("\nCALCULADORA POS-FIXA\nINSTRUCOES:");
        puts("\tDigite cada elemento da expressao separados por um espaco\n\tTermine a expressao com um ponto '.'");
        while(1){


            scanf(" %c", &operador);

            if(operador == '.'){                                                                         // ponto final indica o fim da expressão e quebra o laço de operações.
                printf("\nResultado: %f\n", ldados[topo-1]);
                break;
            }else if (operador != '*' && operador != '+' && operador != '-' && operador != '/'){          // se a entrada não for um operador, é obrigatoriamente um float que será armazenado na pilha.
                ungetc (operador, stdin);                                                                 // essa função retorna a entrada do usuário para o buffer de entrada para ser lido como float.
                scanf (" %f", &operando);
                push (operando, ldados, &topo);
            } else {                                                                                       // se a entrada for um operador, os dois últimos números são desempilhados e a operação é realizada.
                float a, b, c;
                a = pop(&topo, ldados);
                b = pop(&topo, ldados);
                c = operacao(a, b, operador);
                push (c, ldados, &topo);
            }

        }

    }
}

/**Função que cria a pilha*/
void criarPilha(int *topo){

	*topo = 0;

}

/**Função que insere o inteiro 'add' no topo da pilha*/
void push (float add, float *ldados, int *topo){

	ldados[*topo] = add;
	*topo = *topo +1;
	//printf("Numero inserido no topo da pilha: %f\n", ldados[*topo-1]);

}
/**Função que remove o topo da pilha*/
float pop (int *topo, float *ldados){

        if (*topo == 0) {
            printf("Pilha vazia");
            return 0;
        }
        *topo = *topo -1;
        return (ldados[*topo]);
}

/**Função que recebe um caracter e a partir dele faz a operação matemática correta*/
float operacao (float a, float b, char operador){

	switch (operador)
	{
		case '+':
			return b+a;
		case '-':
			return b-a;
		case '*':
			return b*a;
		default:
			return b/a;
	}
}
