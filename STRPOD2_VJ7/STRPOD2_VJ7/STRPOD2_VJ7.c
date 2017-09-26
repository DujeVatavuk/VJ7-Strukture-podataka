/*Zadatak 2. - Grupa 2.
---------------------------------------------------------------------------------------------------------- -
Napisati program koji kreira niz od 20 ponavljanja po 100 sluèajnih brojeva u rasponu od 100 - 200.
Svaki niz ponavljanja(100 brojeva) sprema se u binarno stablo; na naèin, ukoliko broj nije zapisan, upisuje
se u binarno stablo i pri tom se brojaè elementa niza uveæava za jedan; ukoliko je broj veæ upisan
samo se poveæava brojaè unutar èvora stabla.

a) Ispisati sve brojeve koji imaju više od jednog ponavljanja  u svakoj seriji
b) Ispisati sve razlièite brojeve koji imaju više od jednog ponavljanja u svim serijama.

Napomena:
typedef struct _arrayNode
{
	int nbrCounter;
	struct _treeNode *myRoot;
}
typedef struct _treeNode
{
	int number;
	int numberCounter;
	struct _treeNode *Left;
	struct _treeNode *Right;
}_TREENODE;
__________________________________________________________________________________________________________
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

typedef struct stablo *node;
typedef struct stablo
{
	int number;
	int numberCounter;
	node Left;
	node Right;
}stablo;

typedef struct arraynode
{
	int nbrCounter;
	node myRoot;
}arraynode;

int RNG();
node unosUStablo(int, node);
void printBroj(node);
void razlicitBroj(node);
void printRazlicitBroj(arraynode[]);

int main()
{
	srand(time(NULL));
	arraynode niz[20];
	int rNiz[20][100];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			rNiz[i][j] = RNG();
		}
	}

	for (int i = 0; i < 20; i++)
	{
		niz[i].myRoot = NULL;
		for (int j = 0; j < 100; j++)
		{
			niz[i].myRoot = unosUStablo(rNiz[i][j], niz[i].myRoot);
		}
	}

	for (int i = 0; i < 20; i++)
	{
		printBroj(niz[i].myRoot);
		printf("\n");
	}

	printf("\n\n\n");

	printRazlicitBroj(niz);

	return 0;
}

int RNG()
{
	int R;
	R = rand() % 100 + 100;
	return R;
}

node unosUStablo(int x, node S)
{
	if (NULL == S)
	{
		S = (node)malloc(sizeof(stablo));
		S->Left = NULL;
		S->Right = NULL;
		S->number = x;
		S->numberCounter = 1;
	}
	else if (x == S->number)
	{
		S->numberCounter++;
	}
	else if (x > S->number)
	{
		S->Right = unosUStablo(x, S->Right);
	}
	else if (x < S->number)
	{
		S->Left = unosUStablo(x, S->Left);
	}
	return S;
}

void printBroj(node S)
{
	if (NULL != S)
	{
		printBroj(S->Left);
		if (S->numberCounter > 1)
		{
			printf(" %d", S->number);
		}
		printBroj(S->Right);
	}
}

void printRazlicitBroj(arraynode niz[])
{
	
	for (int i = 0; i < 20; i++)
	{
		razlicitBroj(niz[i].myRoot);
	}
}

void razlicitBroj(node S)
{
	static int NIZ[100], check = 1, a = 0;
	if (NULL != S)
	{
		razlicitBroj(S->Left);
		if (S->numberCounter > 1)
		{
			check = 1;
			for (int j = 0; j < 100; j++)//pazi ode 100
			{
				if (S->number == NIZ[j])
				{
					check = 0;
					break;
				}
			}
			if (check)
			{
				printf(" %d", S->number);
				NIZ[a] = S->number;
				a++;
			}
		}
		razlicitBroj(S->Right);
	}
}

/*for (int i = 0; i < 20; i++)
	{
		if (NULL != S)
		{
			printBroj(S->Left);
			if (S->numberCounter > 1)
			{
				printf(" %d", S->number);
			}
			printBroj(S->Right);
		}
		}*/