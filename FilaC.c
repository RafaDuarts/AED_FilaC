#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO{
    char nome[30];
    int idade;
    struct NO *prox;
}NO;

typedef struct FILA{
    NO *ini;
    NO *fim;
}FILA;

void menu();
void inicializaFila(FILA *f);
void enfileira(char *nome, int idade, FILA *f);
void desenfileira(FILA *f);
void imprimeFila(FILA *f);
void limpaFila(FILA *f);

int main(){
    int sel=0, idade=0;
    char nome[30];
    FILA *f1 = (FILA*) malloc(sizeof(FILA));

    if(f1 == NULL){
        printf("\nErro de alocacao!");
        exit(-1);
    } else{        
        inicializaFila(f1);
        
        while (sel != 4){
            menu();
            printf("\nOpcao: ");
            scanf("%d", &sel);
            switch (sel){
            case 0: 

                printf("\nNome: ");
                scanf("%s",nome);
                printf("\nIdade: ");
                scanf("%d",&idade);

                enfileira(nome, idade, f1);
                break;

            case 1: 
                desenfileira(f1);
                break;

            case 2: 
                imprimeFila(f1);
                break;
                
            case 3:
                limpaFila(f1);
                break;

            case 4: 
                limpaFila(f1);
                printf("\nPrograma finalizado =)");
                exit(0);
                break;

            default: 
                printf("\nOpcao Invalida!");
                break;
            }
        }
    }

    return 0;
}



void menu(){
    printf("\n##################################");
    printf("\n-- MENU");
    printf("\n\t0. Insere Pessoa");
    printf("\n\t1. Deleta Pessoa");
    printf("\n\t2. Imprime Fila");
    printf("\n\t3. Limpa Fila");
    printf("\n\t4. Sair");
    printf("\n\n##################################");
}

void inicializaFila(FILA *f){
    f->ini = NULL;
    f->fim = NULL;
}

void enfileira(char *nome, int idade, FILA *f){
    NO *ptr = (NO*) malloc (sizeof(NO));
    if(ptr == NULL){
        printf("\nErro de Alocacao!");
    } else{
        strcpy(ptr->nome, nome);
        ptr->idade = idade;
        ptr->prox = NULL;
        if(f->ini == NULL){
            f->ini = ptr;
        } else{
            f->fim->prox = ptr;
        }
    
    f->fim = ptr;
    }
}

void desenfileira(FILA *f){
    NO *ptr = f->ini;
    if(ptr != NULL){
        f->ini = ptr->prox;
        ptr->prox = NULL;
        free(ptr);
        if(f->ini == NULL){
            f->fim = NULL;
        }
    } else{
        printf("\nFila Vazia!");
    }

}

void imprimeFila(FILA *f){
    NO *ptr = f->ini;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("\n---------------------");
            printf("\nNome: %s", ptr->nome);
            printf("\nIdade: %d", ptr->idade);
            printf("\n---------------------");
            ptr = ptr->prox;
        }

    } else {
        printf("\nFila Vazia!");
    }
}

void limpaFila(FILA *f){

    NO *ptr = f->ini;
    NO *aux;

    if(ptr != NULL){
        while(ptr != NULL){
            aux = ptr->prox;
            free(ptr);
            ptr = aux;
        }

        f->ini = NULL;
        f->fim = NULL;

    } else {
        printf("\nFila Vazia!");
    }
}