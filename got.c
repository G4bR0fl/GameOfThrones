
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

	if(raiz == NULL){

		return(node_create());

	}
	if(contador_no < 4){

		raiz->left = tree_create(raiz->left);

		raiz->right = tree_create(raiz->right);

		contador_no++;
	}

	return(raiz); 
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
   
