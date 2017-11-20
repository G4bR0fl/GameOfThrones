
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "got.h"

int contador_no = 0;

t_node* node_create(){

	t_node* ptr = malloc(sizeof(t_node));/*aloca dinamicamente um no depois coloca NULL nos ponteiros de Character right e left */

	ptr->character = NULL;

	ptr->right = NULL;

	ptr->left = NULL;

	return(ptr);
}

t_node* tree_create(){
	t_node* raiz = malloc(sizeof(t_node));/*aloca memoria para o no raiz*/
	raiz = node_create();
	return raiz;
}

t_node* tree_node(t_node* raiz){
	if(raiz == NULL){
		return node_create();
	}
	else{
		raiz->left = tree_node(raiz->left);
		raiz->right = tree_node(raiz->right);
	}
	return raiz;
}

int height(t_node* h){/*Checa a altura da arvore*/
	int hl, hr;

	if(h == NULL){
		return 0;
	}
	hl = height(h->left)+1;
	hr = height(h->right)+1;

	if(hr >= hl){
		return hr;
	}
	else{
		return hl;
	}
}

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health){

	Character* character = (Character *) malloc(sizeof(Character));
	character->name = _name;
	character->house = _house;
	character->agility = _agility;
	character->strength = _strength;
	character->intelligence = _intelligence;
	character->health = _health;

	return character;
}
	
void inserir_character(Character* character, lista* l){
	if(l->begin == 0 && l->end == 0){

		l->begin->character->character = character;
		l->end->character->character = character;
	}
	else{
		element* atual = l->begin;
		int i;
	}
}

lista* aloca_lista(){
	lista* ptr = (lista *) malloc(sizeof(lista));

	ptr->begin = NULL;
	ptr->end = NULL;

return ptr;
}
   
