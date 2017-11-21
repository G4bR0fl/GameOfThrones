#include <stdio.h>
#include <stdlib.h>
#include "got.h"

int main () {
	int altura = 0;
	FILE *personagens;

	char nome[10000];
	char house[10000];
	char virgula;
	int agility, strength, intelligence, health;

	personagens = fopen("personagens.txt", "r");

	if(personagens == NULL){
		exit(-1);
	}

	while(fscanf(personagens,"%d, %d, %d, %d", &agility, &strength, &intelligence, &health) != EOF){	

		fscanf(personagens, "%[^',']s", nome);
		fgetc(personagens);
		fscanf(personagens, "%[^',']s", house);
		fgetc(personagens);
		fscanf(personagens,"%d, %d, %d, %d", &agility, &strength, &intelligence, &health);

		Character* character = character_create(nome, house, agility, strength, intelligence, health);

		printf("NOME:%s\nCASA:%s\nAgility:%d\nStrength:%d\nIntelligence:%d\nHealth:%d\n", character->name, character->house, character->agility, character->strength, character->intelligence, character->health);
		printf("\n\n");

		t_node* root = tree_create();
		while(altura <= 4){	
			tree_node(root);
			altura = height(root);
		}
	}

	fclose(personagens);

	return 0;
}
