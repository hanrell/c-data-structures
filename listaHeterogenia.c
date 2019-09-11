#include <stdio.h>
#include <stdlib.h>

//TIPOS
struct ponto {
    int x,y;
};

struct circ {
    float raio;
    struct ponto p;
};

struct quad {
    struct ponto p[4];
};

struct tri {
    struct ponto p[3];
};

struct figura {
    int tipo;
    void *f;
    struct figura *prox;
};

//PROTOTIPOS
void criarLista(struct figura**);
void inserir(struct figura**);
void listar(struct figura**);


/**################# MAIN ###################*/

void main (){

    char opcao;
    struct figura *lista;

    while(1){
        puts("\n\tPara criar uma lista: C");
        puts("\tPara inserir um elemento na lista: I");
        puts("\tPara listar: L");
        puts("\tPara encerrar aplicacao: S");
        scanf(" %c", &opcao);

        switch (opcao)
        {
            case 'C':
                criarLista(&lista);
                break;
            case 'I':
                inserir(&lista);
                break;
            case 'L':
                listar(&lista);
                break;
            case 'S':
                exit(0);
            default:
                printf("\nComando inválido\n");
                break;
        }

    }


   

}

void criarLista(struct figura **lista){
    *lista = 0;
}

void inserir (struct figura **lista){

    int tipo;

    puts("\nPara inserir um circulo digite 1");
    puts("Para inserir um quadrado digite 2");
    puts("Para inserir um triangulo digite 3");
    scanf("%d", &tipo);

    struct figura *novo;

    novo = (struct figura*)malloc(sizeof(struct figura));
    if(!novo)return;

    switch(tipo){
        case 1:{
            struct circ *c =(struct circ*)malloc(sizeof(struct circ));
            if(!c)return;

            puts("\nDigite o raio do circulo: ");
            scanf(" %f", &c->raio);
            puts("Digite as coordenadas x e y: ");
            scanf(" %d %d", &c->p.x, &c->p.y);

            novo->tipo = 1;
            novo->f = c;

            break;
        }
        case 2:{
            struct quad *q =(struct quad*)malloc(sizeof(struct quad));
            if(!q)return;

            puts("\nDigite as coordenadas x e y do primeiro ponto: ");
            scanf(" %d %d", &q->p[0].x, &q->p[0].y);
            puts("\nDigite as coordenadas x e y do segundo ponto: ");
            scanf(" %d %d", &q->p[1].x, &q->p[1].y);
            puts("\nDigite as coordenadas x e y do terceiro ponto: ");
            scanf(" %d %d", &q->p[2].x, &q->p[2].y);
            puts("\nDigite as coordenadas x e y do quarto ponto: ");
            scanf(" %d %d", &q->p[3].x, &q->p[3].y);

            novo->tipo = 2;
            novo->f = q;

            break;
        }
        case 3:{
            struct tri *t =(struct tri*)malloc(sizeof(struct tri));
            if(!t)return;

            puts("\nDigite as coordenadas x e y do primeiro ponto: ");
            scanf(" %d %d", &t->p[0].x, &t->p[0].y);
            puts("\nDigite as coordenadas x e y do segundo ponto: ");
            scanf(" %d %d", &t->p[1].x, &t->p[1].y);
            puts("\nDigite as coordenadas x e y do terceiro ponto: ");
            scanf(" %d %d", &t->p[2].x, &t->p[2].y);

            novo->tipo = 3;
            novo->f = t;

            break;
        }

        default: printf("\nTipo invalido\n");
    }

    if(*lista == 0){
        novo->prox = 0;
    } else{
        novo->prox = *lista;
    }

    *lista = novo;

}

void listar(struct figura **lista){

    for (struct figura *aux = *lista; aux; aux = aux->prox) {
        switch (aux->tipo) {
            case 1:
                printf("\nRaio: %f\n", ((struct circ *) (*lista)->f)->raio);
                printf("\nCoordenadas x e y: %d %d\n", ((struct circ *) (*lista)->f)->p.x, ((struct circ *) (*lista)->f)->p.y);
                break;

            case 2:
                printf("\nCoordenadas x e y do primeiro ponto: %d %d\n", ((struct quad *) (*lista)->f)->p[0].x,
                       ((struct quad *) (*lista)->f)->p[0].y);
                printf("\nCoordenadas x e y do segundo ponto: %d %d\n", ((struct quad *) (*lista)->f)->p[1].x,
                       ((struct quad *) (*lista)->f)->p[1].y);
                printf("\nCoordenadas x e y do terceiro ponto: %d %d\n", ((struct quad *) (*lista)->f)->p[2].x,
                       ((struct quad *) (*lista)->f)->p[2].y);
                printf("\nCoordenadas x e y do quarto ponto: %d %d\n", ((struct quad *) (*lista)->f)->p[3].x,
                       ((struct quad *) (*lista)->f)->p[3].y);
                break;

            case 3:
                printf("\nCoordenadas x e y do primeiro ponto: %d %d\n", ((struct tri *) (*lista)->f)->p[0].x,
                       ((struct tri *) (*lista)->f)->p[0].y);
                printf("\nCoordenadas x e y do segundo ponto: %d %d\n", ((struct tri *) (*lista)->f)->p[1].x,
                       ((struct tri *) (*lista)->f)->p[1].y);
                printf("\nCoordenadas x e y do terceiro ponto: %d %d\n", ((struct tri *) (*lista)->f)->p[2].x,
                       ((struct tri *) (*lista)->f)->p[2].y);
                break;
        }
    }

}


