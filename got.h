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
	
}t_node;


typedef struct list_ptr{ /*elemento da lista duplamente encadeada */
					
	t_node* character;

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

#endif
