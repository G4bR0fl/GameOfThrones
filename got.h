#ifndef __GOT_H__
#define __GOT_H__


/*-----------------------AS ESTRUTURAS-----------------------*/

typedef struct { /*Estrutura do personagem*/

	char* name;

	char* house;

	int agility;

	int strength;

	int intelligence;

	int health;

} Character;


typedef struct node { /*nos sao representados por essa estrutura */

	Character* character;

	struct node* left;

	struct node* right;

	//int pos;
	
}t_node;

typedef struct list_ptr{ /*elemento da lista duplamente encadeada */
					
	Character* character;

	struct list_ptr* anterior;

	struct list_ptr* proximo;

}element;


typedef struct { /*ptr para o inicio e o fim da fila */

	element* begin;

	element* end;

}lista;

/* -----------------------AS FUNÇÕES-----------------------*/ 

t_node* node_create();

t_node* tree_create();

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health);

void inserir_character(Character* character, lista* l);

lista* aloca_lista();

lista* lista_aleatoria();

int tree_formula();

t_node* tree_node(t_node* raiz);

int height(t_node* h);

int display();

void display_de_escolha();

void print_list(lista* l);

void character_free(Character* character);

element* aloca_element(Character* character);

void remove_list(lista* l);

void tree_free(t_node* raiz);

void Mensagem_de_ERRO();

void Game_mode(int gamemode);

void Pre_Menu();

void Menu_Gameofthrones();

int escolhe_personagem(lista* lista);

Character* mostra_personagem_escolhido(lista* lista, int escolha);

Character* fight_bot(Character* fighter_one, Character* fighter_two);

Character* fight(Character* fighter_one, Character* fighter_two, int atribute);

void preenche_arvore(t_node* raiz, lista* l, int counter);

void tree_print_preorder(t_node* raiz);

void cria_torneio(t_node* raiz, lista* lista, int contador);

int procura_adversario(t_node* raiz, Character* player, int atributo);

void printa_combate(Character* fighter_one, Character* fighter_two, int atributo);

void seu_personagem(Character* player, int atributo);

void deseja_continuar();

void deseja_continuar_vencedor();



#endif
