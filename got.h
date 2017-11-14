#ifndef __GOT_H__
#define __GOT_H__



typedef struct { /*Estrutura do personagen*/

	char* name;

	char* house;

	int agility;

	int strength;

	int intelligence;

	int health;

}Personagen;


typedef struct ptr { /*nos sao representados por essa estrutura */

	Personagen* character:

	struct ptr* left;

	struct ptr* right;
	
}no_arvore;


typedef struct { /*ponteiro pra raiz*/

	no_arvore* raiz;

}root;

typedef struct list_ptr{ /*elemento da lista duplamente encadeada */

	personagen* character;

	struct list_ptr* anterior;

	struct list_ptr* proximo;

}element;


typedef struct { /*ptr para o inicio e o fim da fila */

	element* begin;

	element* end;

}lista;
