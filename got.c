
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "got.h"
#include <string.h>
#include <unistd.h>

t_node* node_create(){/*Cria nodess para a arvore*/

	t_node* ptr = malloc(sizeof(t_node));/*aloca dinamicamente um no depois coloca NULL nos ponteiros de Character, right e left */

	ptr->character = NULL;

	ptr->right = NULL;

	ptr->left = NULL;

	return(ptr); /*Retorna o no criado*/
}

t_node* tree_create(){/*Cria o node raiz*/
	t_node* raiz = malloc(sizeof(t_node));/*aloca memoria para o no raiz*/
	raiz = node_create();
	return raiz;/*Retorna a raiz criada*/
}

t_node* tree_node(t_node* raiz){/*Cria os 30 nodes restantes da arvore*/
	if(raiz == NULL){
		return node_create();/*Aqui se a raiz passada for nula, quer dizer que ele chegou numa folha(sem ser nas oitavas), entao ele cria mais no*/
	}
	else{
		raiz->left = tree_node(raiz->left);/*Chamada recursiva a esquerda*/
		raiz->right = tree_node(raiz->right);/*Chamada recursiva a direita*/
	}
	return raiz;/*Retorna a raiz da arvore*/
}

int height(t_node* h){/*Checa a altura da arvore*/
	int hl, hr;/*Variaveis que representam altura a direita e altura a esquerda da arvore*/

	if(h == NULL){
		return 0;
	}
	hl = height(h->left)+1;/*Chamada recursiva a esquerda, quando chega no node folha, vai retornando a o valor da funcao se for nulo + 1 = 0+1 */
	hr = height(h->right)+1;/*Chamada recursiva a direita*/
	/*hl e hr sempre sao iguais quando a recursividade no node atual acaba*/
	if(hr >= hl){
		return hr;
	}
	else{
		return hl;
	}
}

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health){/*Funcao que cria o character*/

	Character* character = (Character *) malloc(sizeof(Character));/*Struct alocada dinamicamente*/
	char* character_name = (char *) malloc(sizeof(char)*strlen(_name));/*Nome alocado dinamicamente numa variavel auxiliar*/
	char* character_house = (char *) malloc(sizeof(char)*strlen(_house));/*Casa alocada dinamicamente numa variavel auxiliar*/
	
	strcpy(character_name, _name);/*Copia a string presente na variavel _nome, pra character_name, pois possuem o mesmo tamanho*/
	strcpy(character_house, _house);/*Copia a string presente em _house pra character_house*/

 	character->name = character_name;
	character->house = character_house;
	character->agility = _agility;
	character->strength = _strength;
	character->intelligence = _intelligence;
	character->health = _health;
	/*Aqui acessamos cada elemento da struct por 'character->', 
	*fazendo receber cada variavel da funcao, salvo as auxiliares
	*que por character->house e character->name nao terem tamanhos
	*definidos, foi necessario fazer uma manipulacao com as strings
	*para que nao tivesse ponteiro apontando pro mesmo lugar sempre
	*e consequentemente tendo erro na memoria
	*/
	return character;/*Retornamos a struct recem feita*/
}
	
void inserir_character(Character* character, lista* l){/*Aqui inserimos o character recem criado, na lista duplamente encadeada*/
	if(l->begin == NULL && l->end == NULL){/*Caso a lista esteja vazia, faremos o elemento novo da lista que aponta pra struct receber o inicio e o final*/
		element* personagem = aloca_element(character);
		l->begin = personagem;
		l->end = personagem;
	}
	else{
	/*Caso contrario, sempre inserimos no final da lista, sempre visando manter a logica da
	 *lista duplamente encadeada, com o l->end->proximo(mais recente), sendo NULL
	 */
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

element* aloca_element(Character* character){/*Aqui alocamos um elemento dinamicamente para inserir na lista duplamente encadeada*/
	element* personagem_fila = (element *) malloc(sizeof(element));
	personagem_fila->character = character;

	return personagem_fila;/*Retornamos o elemento alocado*/
}

int display(){/*Nessa funcao apenas lemos o arquivo texto 'menu.txt' que possui uma matriz de caracter. Isso eh mostrado no terminal, no inicio do jogo*/

	system("clear");

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

void display_de_escolha(){/*Aqui nos printamos de um jeito mais bonito a escolha de personagem, do mesmo jeito que a funcao display faz*/

	system("clear");

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

void Mensagem_de_ERRO(){/*Mensagem de erro*/
	printf("Digite [1] para  dar start ao jogo ou [2] para sair do jogo\n");
} 

void Game_mode(int gamemode){/*Aqui depois de ter recebido o retorno da funcao display(), o jogo executa ou sai*/

		if(gamemode == 1){//chama a função

			Menu_Gameofthrones();
		}

		else {

			exit -1;

		}
}

void Pre_Menu(){/*Chama display(), e o gamemode com o resultado de display()*/

	int valor_de_entrada;

	valor_de_entrada = display();

	Game_mode(valor_de_entrada);

}

void Menu_Gameofthrones(){/*Roda o jogo*/

	int escolha;

	int contador = 1;/*Contador para a funcao de criar o torneio*/

	int atributo_escolhido;

	t_node* raiz = tree_create();

	lista* personas = lista_aleatoria();/*Cria uma variavel que recebe uma lista aleatoria*/

	escolha = escolhe_personagem(personas);/*Aqui pode escolher o personagem, depois de serem dadas as respectivas opcoes*/

	Character* player = mostra_personagem_escolhido(personas, escolha);/*Aqui o personagem escolhido, e seus atributos antes omitidos, sao exibidos*/

	cria_torneio(raiz,personas,contador);/*Criacao do torneio*/

	printf("\n\n\n");

	printf("Round 1:\n\n");

	procura_adversario(raiz,player,0);

	printf("\n\n\n");

	printf("Round 2:\n\n");

	procura_adversario(raiz,player,atributo_escolhido);

	printf("\n\n\n");

	printf("Round 3:\n\n");

	procura_adversario(raiz,player,atributo_escolhido);

	printf("\n\n\n");

	printf("Round 4:\n\n");

	procura_adversario(raiz,player,atributo_escolhido);

	if(raiz->character == player){
		deseja_continuar_vencedor();	
	}

}

void deseja_continuar_vencedor(){/*Aqui nos damos a opcao do jogador continuar mesmo depois de ter vencido*/

	int escolha;

	printf("Voce e o bichao mesmo hein, conquistou o Trono de Ferro e toda a Westeros\n");

	printf("Parabens!!!!\n\n");
	printf("Quer jogar novamente?");
	printf("\n\n");
	printf("[1] - Sim,quero jogar novamente\n");
	printf("[2] - Foda-se essa porra quero e ir embora\n");

	scanf("%d", &escolha);

	while(escolha != 1 && escolha != 2){
		printf("Ganhar nao significa que voce pode digitar errado,amor\n");
		scanf("%d", &escolha);
	}

	Game_mode(escolha);

}

void seu_personagem(Character* player, int atributo_escolhido){/*Mostra os atributos do personagem escolhido*/

	printf("Seu personagem : %s da casa %s\n",player->name,player->house);

	switch(atributo_escolhido){

		case 1:

			printf("X)X            : XX\n");

			break;

		default:

			printf("1)Agility      : %d\n",player->agility);

			break;
	}

	switch(atributo_escolhido){

		case 2:

			printf("X)X            : XX\n");

			break;

		default:

			printf("2)Strength     : %d\n",player->strength);

			break;
	}


	switch(atributo_escolhido){

		case 3:

			printf("X)X            : XX\n");

			break;

		default:

			printf("3)Intelligence : %d\n",player->intelligence);

			break;
	}

	switch(atributo_escolhido){
		case 4:

			printf("X)X            : XX\n");

			break;

		default:

			printf("4)Health       : %d\n", player->health);

			break;
	}

}


int procura_adversario(t_node* raiz, Character* player, int atributo){/*Aqui ele navega a arvore, buscando o adversario do player que ta jogando, retornando o atributo usado na luta, caso seja um player*/

		Character* Vencedor; /*Ponteiro que vai receber quem ganhou dos personagens. Se ele for o player ele sai, se nao continua*/

			if(raiz != NULL && raiz->character == NULL){

				if(raiz->left->character != NULL && raiz->right->character != NULL){

				 	if(raiz->left->character == player){

				 		printf("\n\n");

				 		seu_personagem(player,atributo);


				 		printf("Seu adversario : %s da casa %s\n", raiz->right->character->name, raiz->right->character->house);

				 		printf("\n\nSelecione um atributo: ");

				 		scanf("%d", &atributo);

				 		 Vencedor = fight(player, raiz->right->character, atributo);

				 		 	if(Vencedor != player){

				 		 		printf("\t\t\tVoce perdeu T-T\t\t\t\n");

				 		 		printa_combate(player, raiz->right->character, atributo);

				 		 		deseja_continuar();

				 		 	}
				 		 	else{

				 		 		printf("\t\t\tVoce Ganhou :P\t\t\t\n");

				 		 		printa_combate(player,raiz->right->character, atributo);
				 		 	}

				 	}
				 	else if(raiz->right->character == player){

				 		printf("\n\n");

				 		seu_personagem(player,atributo);

				 		printf("Seu adversario : %s da casa %s\n", raiz->left->character->name, raiz->left->character->house);

				 		printf("\n\nSelecione um atributo: ");

				 		scanf("%d", &atributo);

				 		 Vencedor = fight(raiz->left->character, player, atributo);

				 		 if(Vencedor != player){

				 		 		printf("\t\t\tVoce perdeu T-T\t\t\t\n");

				 		 		printa_combate(player, raiz->left->character, atributo);

				 		 		deseja_continuar();

				 		 	}
				 		 	else{

				 		 		printf("\t\t\tVoce Ganhou :P\t\t\t\n");

				 		 		printa_combate(player,raiz->left->character, atributo);
				 		 	}
				 	}
				 	else {

				 		Vencedor = fight_bot(raiz->left->character,raiz->right->character);
				 	}

				 	raiz->character = Vencedor;

				}

				procura_adversario(raiz->left,player,atributo);
				procura_adversario(raiz->right,player,atributo);
			}

		if(atributo != 0){

			return atributo;

		}

}

void deseja_continuar(){/*Printa no screen as opcoes, e chama Game_mode(), pra continuar ou nao*/

	int escolha;

	printf("Voce se fudeu pela a Guerra ao Trono de Ferro e acabou morrendo deseja continuar?\n");
	printf("\n\n");
	printf("[1] - Sim,quero tentar denovo\n");
	printf("[2] - Foda-se essa porra quero e ir embora\n");

	scanf("%d", &escolha);

	while(escolha != 1 && escolha != 2){
		printf("Nao basta perder ainda digita errado meu deus!!!!\n");
		scanf("%d", &escolha);
	}

	Game_mode(escolha);
}

void printa_combate(Character* fighter_one,Character* fighter_two, int combate){

	switch(combate){

		case 1:

			printf("%s (%d Agility) vs %s (%d Agility)\n",fighter_one->name, fighter_one->agility, fighter_two->name,fighter_two->agility);

			break;

		case 2:

			printf("%s (%d Strength) vs %s (%d Strength)\n", fighter_one->name, fighter_one->strength, fighter_two->name,fighter_two->strength);
		
			break;

		case 3:

			printf("%s (%d Intelligence) vs %s (%d Intelligence)\n", fighter_one->name,fighter_one->intelligence,fighter_two->name,fighter_two->intelligence);
			
			break;

		case 4:

			printf("%s (%d Health) vs %s (%d Health)\n", fighter_one->name, fighter_one->health,fighter_two->name,fighter_two->health);
	}

}

Character* fight(Character* fighter_one, Character* fighter_two, int atributo){/*Aqui temos a funcao de chamar a luta, que recebe o jogador 1 e o jogador 2*/

	Character* winner;/*Ponteiro pra Character, que recebe o vencedor, podendo ser fighter_one ou fighter_two*/

	switch(atributo){/*Compara os atributos dos lutadores, dependendo do atributo escolhido*/

		case 1:

			if(fighter_one->agility >= fighter_two->agility){

				winner = fighter_one;

				return winner;
			}

			else {

				winner = fighter_two;

				return winner;
			}

			break;

		case 2:

			if(fighter_one->strength >= fighter_two->strength){

				winner = fighter_one;

				return winner;
			}

			else {

				winner = fighter_two;

				return winner;

			}

			break;

		case 3:

			if(fighter_one->intelligence >= fighter_two->intelligence){

				winner = fighter_one;

				return winner;
			}

			else {

				winner = fighter_two;

				return winner;
			}

			break;

		case 4:

			if(fighter_one->health >= fighter_two->health){

				winner = fighter_one;

				return winner;
			}
			else {

				winner = fighter_two;

				return winner;
			}

			break;

	}

}

Character* fight_bot(Character* fighter_one, Character* fighter_two){/*Aqui temos a luta dos bots, caso procura_adversario() nao ache o player*/

	int random;/*Variavel que vai receber um numero aleatorio*/

	Character* winner;

	struct timespec seed;/*Struct da time.h*/

	clock_gettime(CLOCK_REALTIME, &seed);

	srand(seed.tv_nsec); /*Vai na struct seed, e usa o tempo em nanossegundos*/

	random = rand()%4+1; /*Gera numeros de 1 ate 4*/

	printa_combate(fighter_one,fighter_two,random);

	switch(random){/*De acordo com o numero gerado no random, o atributo eh escolhido*/

		case 1:

			if(fighter_one->agility >= fighter_two->agility){

				winner = fighter_one;

				return winner;
			}

			else {

				winner = fighter_two;

				return winner;
			}

			break;

		case 2:

			if(fighter_one->strength >= fighter_two->strength){

				winner = fighter_one;

				return winner;
			}

			else {

				winner = fighter_two;

				return winner;

			}

			break;

		case 3:

			if(fighter_one->intelligence >= fighter_two->intelligence){

				winner = fighter_one;

				return winner;
			}

			else {

				winner = fighter_two;

				return winner;
			}

			break;

		case 4:

			if(fighter_one->health >= fighter_two->health){

				winner = fighter_one;

				return winner;
			}
			else {

				winner = fighter_two;

				return winner;
			}

			break;

	}

}

void cria_torneio(t_node* raiz, lista* lista, int contador){/*Aqui a arvore eh criada*/

	int altura = 0;

		while(altura <= 4){

			tree_node(raiz);

			altura = height(raiz);

		}

		preenche_arvore(raiz,lista,contador);

}

Character* mostra_personagem_escolhido(lista* lista, int escolha){/*Aqui o personagem escolhido pelo jogador eh mostrado*/

	element* aux_ptr;
	Character* player;

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


	player = aux_ptr->character;

	return player;
}

int escolhe_personagem(lista* lista){
	/*Aqui o display de escolha eh mostrado, logo apos o numero eh lido e a funcao retorna o suposto 
    *personagem escolhido. Sendo que aqui printa todas as opcoes que foram jogadas pra lista aleatoriamente
	*/
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

lista* lista_aleatoria(){/*Aqui eh gerada uma lista, com os personagens numa ordem totalmente randomica, dentre os 20 do txt, somente 16 entram*/

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
  
void print_list(lista* l){/*Funcao pra printar a lista, usada em teste para ver se a lista correspondia a nossa logica, usado mais para debugar*/
	element* aux = l->begin;
	while(aux != NULL){
		printf("%s -> ", aux->character->name);
		aux = aux->proximo;
	}
	printf("\n");
}

void character_free(Character* character){/*Funcao de dar free na struct Character*/
	free(character->name);
	free(character->house);
	free(character);
	character->name = NULL;
	character->house = NULL;
	character = NULL;
}	

void remove_list(lista* l){/*Funcao que cuida do free da lista junto com o free da struct Character*/
	element* ptr = l->begin;
	if(l->begin == NULL && l->end == NULL){
		printf("Lista vazia!\nSaindo\n");
		exit(-1);
	}
	while(ptr != NULL){
		l->begin = l->begin->proximo;
		character_free(ptr->character);
		free(ptr);
		ptr = l->begin;
	}
	l->end = ptr;
	free(l);
}

void tree_free(t_node* raiz){/*Essa funcao da free na arvore gerada*/
	if(raiz == NULL){
		printf("Arvore vazia!\n");
	}
	else{
		if(raiz->left != NULL && raiz->right != NULL){
			tree_free(raiz->left);
			tree_free(raiz->right);
		}
		if(raiz->left == NULL && raiz->right == NULL){
			free(raiz);
			return;
		}
	}
}

void preenche_arvore(t_node* raiz, lista* l, int counter){/*Essa funcao preenche os nos folhas da arvore principal que foi gerada*/
	int i;
	if(raiz->left != NULL && raiz->right != NULL){
		preenche_arvore(raiz->left, l, counter*2);
		preenche_arvore(raiz->right, l, (counter*2) +1);
	}
	else{
		counter -= 16;
		element* ptr = l->begin;
		if(counter == 0){
			raiz->character = l->begin->character;
		}
		else{
			i = counter;
			while(i > 0){
				ptr = ptr->proximo;
				i--;
			}
			raiz->character = ptr->character;
		}
	}
}

void tree_print_preorder(t_node* raiz){/*Essa funcao printa os personagens em pre_ordem, como especificado no trabalho*/
    if(raiz != NULL){
        if(raiz->character != NULL){
        	printf("%s\n", raiz->character->name);
        }
        tree_print_preorder(raiz->left);
        tree_print_preorder(raiz->right);
    }
}

