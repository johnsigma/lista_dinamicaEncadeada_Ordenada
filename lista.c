#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst==NULL)
        return 1; //lista vazia
    else
        return 0; //lista não vazia
}

int insere_ord(Lista *lst, int elem){
    Lista N=(Lista) malloc(sizeof(struct no));
    if(N==NULL)
        return 0; //falha na alocação
    N->info=elem; //insere o valor do elemento no nó
    if(lista_vazia(*lst) || elem<=(*lst)->info){
        N->prox=*lst; //aponta para o 1º nó atual da lista
        *lst=N; //faz a lista apontar para o novo nó
        return 1;
    }
    //percorimento da lista (elem >1º nó da lista)
    Lista aux=*lst; //faz aux apontar para o 1º nó
    while(aux->prox!=NULL && aux->prox->info<elem)
        aux=aux->prox; //avança
    N->prox=aux->prox;
    aux->prox=N;
    return 1;
}

int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst)==1 || elem<(*lst)->info)
        return 0; //falha

    Lista aux=*lst; //ponteiro auxiliar para o 1º elemento

    if(elem==(*lst)->info){ //remove o 1º elemento da lista
        *lst=aux->prox; //Lista aponta para o 2º nó
        free(aux); //libera memória alocada
        return 1; //sucesso na remoção
    }

    //percorrimento até o final ou até achar elem ou elem maior
   while(aux->prox!=NULL && aux->prox->info<elem)
        aux=aux->prox;
   if(aux->prox==NULL || aux->prox->info>elem)
        return 0; //falha

   //remove elemento (após o 1º nó a lista
   Lista aux2=aux->prox; //aponta para o nó a ser removido
   aux->prox=aux2->prox; //retira o nó da lista
   free(aux2); //libera memória alocada
   return 1; //sucesso na remoção
}

Lista imprime_lista(Lista lst){
    if(lista_vazia(lst)){
        printf("Lista vazia!\n\n");
        return 0;
    }
    Lista aux=lst;
    printf("Lista: ");
    while(aux!=NULL){
        printf("%d ", aux->info);
        aux=aux->prox;
    }
    printf("\n\n");
}

int tamanho(Lista lst){
    int i=0;
    Lista aux=lst;
    while(aux!=NULL){
        i++;
        aux=aux->prox;
    }
    return i;
}

int menor_elem(Lista *lst){
    if(lista_vazia(*lst)==1) //verifica se a lista é vazia
        return 0;

    Lista aux=*lst;
    *lst=aux->prox;
    free(aux);

    return 1; //sucesso na remoção
}

int remove_impares(Lista *lst){
    Lista aux=*lst;
    Lista aux2=NULL;

    if((*lst)->info%2==1){ //remove o 1º elemento da lista
        *lst=aux->prox; //Lista aponta para o 2º nó
        free(aux); //libera memória alocada
    }

    aux=*lst;

    while(aux!=NULL){
        if(aux->info%2!=1){
            aux2=aux;
            aux=aux->prox;
        }else{
            aux2->prox=aux->prox;
            free(aux);
            aux=aux2;
        }
    }
    return 1;
}



Lista intercala(Lista *lst1, Lista *lst2){
    Lista lst3=cria_lista();
    Lista aux1=*lst1;
    Lista aux2=*lst2;
    Lista aux3=lst3;

    while(aux1!=NULL && aux2!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        if(N==NULL)
            return 0;
        if(aux1->info<=aux2->info){
            N->info=aux1->info;
            aux1=aux1->prox;
        }else{
            N->info=aux2->info;
            aux2=aux2->prox;
        }
        if(lst3==NULL)
            lst3=N;
        else
            aux3->prox=N;
        aux3=N;
    }

    while(aux1!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        if(N==NULL)
            return 0;
        N->info=aux1->info;
        aux1=aux1->prox;
        if(lst3==NULL)
            lst3=N;
        else
            aux3->prox=N;
        aux3=N;
    }

    while(aux2!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        if(N==NULL)
            return 0;
        N->info=aux2->info;
        aux2=aux2->prox;
        if(lst3==NULL)
            lst3=N;
        else
            aux3->prox=N;
        aux3=N;
    }

    if(aux3!=NULL)
        aux3->prox=NULL;

    return lst3;
}

int iguais(Lista *lst1, Lista *lst2){
    Lista aux=*lst1;
    Lista aux2=*lst2;

    while(aux!=NULL && aux2!=NULL){
        if(aux->info!=aux2->info){
            printf("\nAs listas não são iguais!\n");
            return 0;
        }
        aux=aux->prox;
        aux2=aux2->prox;
    }

    printf("\nAs listas são iguais!\n\n");

    return 1;
}
