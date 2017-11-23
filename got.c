
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "got.h"
#include <string.h>

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
	char* character_name = (char *) malloc(sizeof(char)*strlen(_name));
	char* character_house = (char *) malloc(sizeof(char)*strlen(_house));

	strcpy(character_name, _name);
	strcpy(character_house, _house);

 	character->name = character_name;
	character->house = character_house;
	character->agility = _agility;
	character->strength = _strength;
	character->intelligence = _intelligence;
	character->health = _health;

	//free(character_name);
	//free(character_house);

	return character;
}
	
void inserir_character(Character* character, lista* l){
	if(l->begin == NULL && l->end == NULL){
		element* personagem = aloca_element(character);
		l->begin = personagem;
		l->end = personagem;
	}
	else{
		element* aux = aloca_element(character);
		l->end->proximo = aux;
		aux->anterior = l->end;
		l->end = aux;
		l->end->proximo = NULL;
	}
}

lista* aloca_lista(){
	lista* ptr = (lista *) malloc(sizeof(lista));

	ptr->begin = NULL;
	ptr->end = NULL;

	return ptr;
}

element* aloca_element(Character* character){
	element* personagem_fila = (element *) malloc(sizeof(element));
	personagem_fila->character = character;

	return personagem_fila;
}

int display(){
	char mat[17][45];
	int i, j, gamemode;
	i = j = 0;
	FILE *menu;
	menu = fopen("menu.txt", "r");
	while(!feof(menu)){
		for(i = 0; i < 17; i++){
			for(j = 0; j < 45; j++){
				fscanf(menu, "%c", &mat[i][j]);
			}
		}
	}
	for(i = 0; i < 17; i++){
		for(j = 0; j < 45; j++){
			printf("%c", mat[i][j]);
		}
	}
		printf("################");
		printf("\n\n");
	fclose(menu);

	printf("[1] Start New Game\n[2] Quit Game\n");
	scanf("%d", &gamemode);
	return gamemode;
}
  

void print_list(lista* l){
	element* aux = l->begin;
	while(aux != NULL){
		printf("%s -> ", aux->character->name);
		aux = aux->proximo;
	}
	printf("\n");
}

void character_free(Character* character){
	free(character->name);
	free(character->house);
	free(character);
	character->name = NULL;
	character->house = NULL;
	character = NULL;
}	

void remove_list(lista* l){
	element* ptr = l->begin;
	if(l->begin == NULL && l->end == NULL){
		printf("Lista vazia!\nSaindo\n");
		exit(-1);
	}
	while(ptr != NULL){
		l->begin = l->begin->proximo;
		free(ptr);
		ptr = l->begin;
	}
	l->end = ptr;
	free(l);
}

void tree_free(t_node* tree){
	if(tree == NULL){
		printf("Arvore vazia!\n");
	}
	else{
		if(tree->left != NULL && tree->right != NULL){
			tree_free(tree->left);
			tree_free(tree->right);
		}
		if(tree->left == NULL && tree->right == NULL){
			free(tree);
			return;
		}
	}
}