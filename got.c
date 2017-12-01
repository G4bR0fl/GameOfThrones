
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "got.h"
#include <string.h>
#include <unistd.h>

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
	char mat[31][99];
	int i, j, gamemode;
	i = j = 0;
	FILE *menu;
	menu = fopen("menu.txt", "r");
	while(!feof(menu)){
		for(i = 0; i < 31; i++){
			for(j = 0; j < 99; j++){
				fscanf(menu, "%c", &mat[i][j]);
			}
		}
	}
	for(i = 0; i < 31; i++){
		for(j = 0; j < 99; j++){
			printf("%c", mat[i][j]);
		}
	}
		printf("\n\n");
	fclose(menu);


		scanf("%d", &gamemode);

		while(gamemode != 1 && gamemode != 2){//loop pra condiçao de valor correto

				Mensagem_de_ERRO();
				scanf("%d", &gamemode);

		}


	return gamemode;
}

void display_de_escolha(){

	char mat[8][109];

	int i = 0, j = 0;

	FILE *escolha;

	escolha = fopen("escolha.txt", "r");

	printf("\n\n");

	while(!feof(escolha)){

		for(i = 0;i < 8;i++){
			for(j = 0;j < 109;j++){

				fscanf(escolha, "%c", &mat[i][j]);
			}
		}
	}

	for(i = 0;i < 8;i++){
		for(j = 0; j < 109;j++){

			printf("%c", mat[i][j]);

		}
	}

	printf("\n\n");

	fclose(escolha);
}

void Mensagem_de_ERRO(){

	printf("Digite [1] para  dar start ao jogo ou [2] para sair do jogo\n");

} 

void Game_mode(int gamemode){

		if(gamemode == 1){//chama a função

			Menu_Gameofthrones();
		}

		else {

			exit -1;

		}
}

void Pre_Menu(){

	int valor_de_entrada;

	valor_de_entrada = display();

	Game_mode(valor_de_entrada);

}

void Menu_Gameofthrones(){
	int escolha;

	lista* personas = lista_aleatoria();

	print_list(personas);

	escolha = escolhe_personagem(personas);

	mostra_personagem_escolhido(personas, escolha);





	
}

element* mostra_personagem_escolhido(lista* lista, int escolha){

	element* aux_ptr;
	element* ptr_player;

	int contador = 1;

	aux_ptr = lista->begin;


	while(contador < escolha){

		aux_ptr = aux_ptr->proximo;
		contador++;
	}

	printf("Seu personagem: %s ", aux_ptr->character->name);
	printf("da casa %s\n", aux_ptr->character->house);
	printf("1)Agility      : %d\n", aux_ptr->character->agility);
	printf("2)Strength     : %d\n", aux_ptr->character->strength);
	printf("3)Intelligence : %d\n", aux_ptr->character->intelligence);
	printf("4)Health       : %d\n", aux_ptr->character->health);


	ptr_player = aux_ptr;

	return ptr_player;
}

int escolhe_personagem(lista* lista){

	display_de_escolha();

	sleep(2);

	printf("\n");

	int random;

	struct timespec seed;

	clock_gettime(CLOCK_REALTIME, &seed);

	srand(seed.tv_nsec);

	int contador = 1;

	element* aux_ptr = lista->begin;

	while(aux_ptr != NULL){

		random = rand()%4+1;

		printf("Personagem %d :\n", contador);

		switch(random){

			case 1 :

				printf("Agility: %d ", aux_ptr->character->agility);

				break;

			default :

				printf("Agility: ?? ");

				break;

		}

		switch(random){

			case 2:

				printf("Strength: %d ", aux_ptr->character->strength);

				break;

			default :

				printf("Strength: ?? ");

				break;
		}

		switch(random){

			case 3:

				printf("Intelligence: %d ", aux_ptr->character->intelligence);

				break;

			default :

				printf("intelligence: ?? ");

				break;
		}

		switch(random){

			case 4:

				printf("Health: %d ", aux_ptr->character->health);

				break;

			default :

				printf("Health: ?? ");

				break;
		}

		printf("\n\n");

		aux_ptr = aux_ptr->proximo;

		contador++;
	}

	int nro_que_escolheu; 

	scanf("%d", &nro_que_escolheu);

	return nro_que_escolheu;

}


lista* lista_aleatoria(){

	FILE* personagens;/*ptr para arquivo */

	char nome[10000];
	char house[10000];
	int agility, strength, intelligence, health;

	personagens = fopen("personagens.txt", "r");

	lista* l = aloca_lista();
	
	if(personagens == NULL){

		printf("Arquivo dos personagens do jogo inexistente T-T\n");/*testa se o arquivo abre */

		exit(-1);
	}

	/*essa parte do codigo cria um vetor de 16 com aleatorios que vai 1 ate 20 */

	int  i, j = 0, random, existe_numero;

	struct timespec seed;

	int vet[16];

	while(j < 16){

		clock_gettime(CLOCK_REALTIME, &seed);

		srand(seed.tv_nsec);

		random = rand()%20;

		for(i = 0; i < 16;i++){

			if(random == vet[i]){

				existe_numero = 1;
			}
		}

		if(existe_numero != 1){

			vet[j] = random;

			j++;
		}

		existe_numero = 0;
	}

	int k = 0;

	/*parte do codigo que pega personagens aleatorios de acordo com os valores no vet[]*/

	while(k < 16){

		for(i = 0; i < vet[k];i++){

			fscanf(personagens,"%[^',']s",nome);
			fgetc(personagens);
			fscanf(personagens, "%[^',']s", house);
			fgetc(personagens);
			fscanf(personagens, "%d, %d, %d, %d",&agility,&strength,&intelligence,&health);

		}

		Character* character = character_create(nome, house, agility, strength, intelligence, health);

		inserir_character(character, l);

		rewind(personagens);

		k++;

	}


	return l;

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
