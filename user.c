#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main(){

setlocale(LC_ALL, "Portuguese_Brazil");

    Lista lista1;
    lista1=cria_lista();

    menor_elem(&lista1);
    printf("A lista tem %d elementos!\n",tamanho(lista1));

    imprime_lista(lista1);

    insere_ord(&lista1,1);
    insere_ord(&lista1,8);
    insere_ord(&lista1,0);
    insere_ord(&lista1,19);
    insere_ord(&lista1,2);
    insere_ord(&lista1,7);
    insere_ord(&lista1,9);
    insere_ord(&lista1,23);
    insere_ord(&lista1,8);

    printf("A lista tem %d elementos!\n",tamanho(lista1));
    imprime_lista(lista1);

    menor_elem(&lista1);
    printf("A lista tem %d elementos!\n",tamanho(lista1));
    imprime_lista(lista1);

    remove_impares(&lista1);

    menor_elem(&lista1);
    printf("A lista tem %d elementos!\n",tamanho(lista1));
    imprime_lista(lista1);

    Lista lista2=cria_lista();
    Lista lista3=cria_lista();


    insere_ord(&lista3,4);
    insere_ord(&lista3,2);
    insere_ord(&lista3,10);
    insere_ord(&lista3,1);
    insere_ord(&lista3,1025);

    insere_ord(&lista2,0);
    insere_ord(&lista2,14);
    insere_ord(&lista2,9);
    insere_ord(&lista2,92);

    Lista lista4;

    lista4=intercala(&lista3,&lista2);

    imprime_lista(lista4);
    iguais(&lista3,&lista4);

    Lista lista5=cria_lista();
    Lista lista6=cria_lista();

    insere_ord(&lista5,23);
    insere_ord(&lista5,30);
    insere_ord(&lista5,12);
    insere_ord(&lista5,12);

    insere_ord(&lista6,12);
    insere_ord(&lista6,30);
    insere_ord(&lista6,12);
    insere_ord(&lista6,23);

    imprime_lista(lista5);
    imprime_lista(lista6);

    iguais(&lista5,&lista6);

    free(lista1);
    free(lista2);
    free(lista3);
    free(lista4);
    free(lista5);
    free(lista6);

    return 0;
}
