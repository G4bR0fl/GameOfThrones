#include <stdio.h>
#include <stdlib.h>


int main () {

	FILE *personagens;

	char nome[40];
	char house[40];
	char virgula;
	int agility, strength, intelligence, health;

	personagens = fopen("personagens.txt", "r");

	if(personagens == NULL){

		exit;
	}


while(fscanf(personagens,"%d, %d, %d, %d", &agility, &strength, &intelligence, &health) != EOF){	

	fscanf(personagens, "%[^',']s", nome);

	fgetc(personagens);

	fscanf(personagens, "%[^',']s", house);

	fgetc(personagens);


	fscanf(personagens,"%d, %d, %d, %d", &agility, &strength, &intelligence, &health);





	printf("NOME:%s\nCASA:%s\nAgility:%d\nStrength:%d\nIntelligence:%d\nHealth:%d\n", nome, house,agility,strength,intelligence,health);

	printf("\n\n");
}

	fclose(personagens);




	

	return 0;
}