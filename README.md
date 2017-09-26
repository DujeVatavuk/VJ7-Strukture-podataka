# VJ7-Strukture-podataka
Vjezba 7

Napisati program koji kreira niz od 20 ponavljanja po 100 slučajnih brojeva u rasponu od 100 - 200.
Svaki niz ponavljanja(100 brojeva) sprema se u binarno stablo; na način, ukoliko broj nije zapisan, upisuje
se u binarno stablo i pri tom se brojač elementa niza uvećava za jedan; ukoliko je broj već upisan
samo se povećava brojač unutar čvora stabla.

a) Ispisati sve brojeve koji imaju više od jednog ponavljanja  u svakoj seriji
b) Ispisati sve različite brojeve koji imaju više od jednog ponavljanja u svim serijama.

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
