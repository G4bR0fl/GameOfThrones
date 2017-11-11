#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__	

typedef struct elemento{
	int dado;
	struct elemento* proximo;
	struct elemento* anterior;
}t_ele;

typedef struct{
	t_ele* inicio;
	t_ele* fim;
}Lista;

t_ele* aloca_elemento(int valor);
Lista* aloca_lista();

int checar_lista(Lista* list);
void inserir_inicio(Lista* list, int valor);
void inserir_final(Lista* list, int valor);
void acessa_inicio(Lista* list);
void acessa_final(Lista* list);
void inserir(int pos, int valor, Lista* list);
void remove_list(Lista* list);
void print_list(Lista* list);
void before_n_after(Lista* list, int pos);


#endif