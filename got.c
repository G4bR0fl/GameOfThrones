#include <stdio.h>
#include <stdlib.h>
#include "got.h"


t_node* node_create(){

	t_node* ptr = malloc(sizeof(t_node));/*aloca dinamicamente um no depois coloca NULL nos ponteiros de Character right e left */

	ptr->character = NULL;

	ptr->right = NULL;

	ptr->left = NULL;

	return(ptr);
}


t_node* tree_create(){

	t_node* raiz = malloc(sizeof(t_node));/*cria a arvore seta seus ponteiros pra direita e esquerda pra NULL e depois retorna o ponteira pra raiz */

	raiz->character = NULL;

	raiz->left = NULL;

	raiz->right = NULL;

	return(raiz); 
}