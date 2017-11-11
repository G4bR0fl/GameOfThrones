#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
 
t_ele* aloca_elemento(int valor){
    t_ele* ptr = (t_ele *) malloc(sizeof(t_ele));
 
    ptr->dado = valor;
    ptr->proximo = NULL;
    ptr->anterior = NULL;
 
    return ptr;
}
 
Lista* aloca_lista(){
    Lista* ptr = (Lista *) malloc(sizeof(Lista));
 
    ptr->inicio = NULL;
    ptr->fim = NULL;
 
    return ptr;
}
 
int checar_lista(Lista* list){
    return(list->inicio == NULL && list->fim == NULL);
}
 
void inserir_inicio(Lista* list, int valor){
    t_ele* elemento = aloca_elemento(valor);
    if(checar_lista(list)){
        list->inicio = elemento;
        list->fim = elemento;
    }
    else{
        elemento->proximo = list->inicio; /*Novo elemento aponta pro antigo primeiro elemento*/
        list->inicio->anterior = elemento; /*O anterior do primeiro elemento que era NULL, agora aponta pro primeiro*/
        list->inicio = elemento; /*Inicio aponta pro novo elemento*/
    }
    if(list->fim == NULL){
        list->fim = list->inicio; /*O final da lista aponta pro primeiro elemento*/
    }
}
 
void inserir_final(Lista* list, int valor){
    t_ele* elemento = aloca_elemento(valor);
    if(checar_lista(list)){
        list->inicio = elemento;/*Se a lista esta vazia, então inicio aponta pra elemento*/
    }
    else{
        list->fim->proximo = elemento;/*O 'proximo' do ultimo elemento da lista, aponta pro novo elemento adicionado*/
        elemento->anterior = list->fim;/*O 'anterior' do ultimo elemento, aponta pro penultimo elemento*/
    }
    list->fim = elemento;/*Fim aponta pro ultimo elemento da lista*/
}
 
void inserir(int pos, int valor, Lista* list){
    if(pos <= 0){
        inserir_inicio(list, valor);/*Se a posicao dada for menor ou igual a zero, insere no inicio*/
    }
    else{
        t_ele* atual = list->inicio;
        int i;
        for(i = 0; i < pos; i++){
            atual = atual->proximo;
            /*Percorre a lista*/
        }
 
        if(atual == NULL || atual == list->fim){
            inserir_final(list, valor);
        }
        else{
            t_ele* elemento = aloca_elemento(valor);
            elemento->proximo = atual->proximo;
            atual->proximo = elemento;
        }
    }
}
 
void acessa_inicio(Lista* list){
    printf("O primeiro elemento da lista eh: %d\n", list->inicio->dado);
}
/*Ambos acessos estão inválidos. CONSERTAR*/
void acessa_final(Lista* list){
    printf("O ultimo elemento da lista eh: %d\n", list->fim->dado);
}
 
void tam_list(Lista* list){
    int counter = 0;
    if(checar_lista(list)){
        printf("LISTA VAZIA\n");
    }
    else{
        t_ele* ptr = list->inicio;
        while(ptr != NULL){
            counter++;
            ptr = ptr->proximo;
        }
        printf("A lista possui %d elementos.\n", counter);
    }
}
 
void print_list(Lista* list){
    t_ele* ptr = list->inicio;
    int i;
    if(checar_lista(list)){
        printf("Lista ta vazia!\n");
        return;
    }
    while(ptr != NULL){
        printf("%d -> ", ptr->dado);
        ptr = ptr -> proximo;
    }
    printf(" NULL\n");
}
 
void remove_list(Lista* list){
    t_ele* ptr = list->inicio;
    int i;
    if(checar_lista(list) ){
        printf("LISTA VAZIA\n");
        return;
    }
    while(ptr != NULL){
        list->inicio = list->inicio->proximo;
        free(ptr);
        ptr = list->inicio;
    }
 
  free(list);
}

void before_n_after(Lista* list, int pos){
	int i;
	t_ele* aux = list->inicio;
	for(i = 0; i < pos; i++){
		aux = aux->proximo;
	}
	printf("Elemento selecionado: %d\n", aux->dado);
	if(aux->anterior != NULL){
		printf("Elemento anterior ao selecionado: %d\n", aux->anterior->dado);
	}
	else{
		printf("O elemento selecionado eh o primeiro da lista\n");
	}
	if(aux->proximo != NULL){
		printf("Elemento posterior ao selecionado: %d\n", aux->proximo->dado);
	}
	else{
		printf("O elemento selecionado eh o ultimo da lista\n");
	}
}