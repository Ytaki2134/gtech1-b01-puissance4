#include <stdio.h>
#define NBL 6
#define NBC 7

int tab[NBL][NBC];
int i, j;

void init(void) {
 printf("-------------\n");
  for(i=0; i < NBL; i++) {
    for(j = 0; j < NBC; j++)
    {
      printf(". ",tab[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
  printf("1 2 3 4 5 6 7\n");
}

int gameOn = 1;
int turns = 1;
int column = 0;

int main(void) {
  init();

  printf(" ======================================== Bienvenue dans le jeu du puissance 4 ======================================== \n");
  printf("                                              <Ce jeu se joue à 2 joueurs>\n\n");
  printf("BUT DU JEU: Aligner 4 symboles identique propre à chaque joueur dans \nla grille de jeu de façon horizontale, verticale ou diagonale avant l'autre joueur.\n\n");
  printf("COMMENT JOUER: Chacun son tour, les joueurs vont entrer le numéro de la colonne dans \nlaquelle ils veulent que leur symbole entre et se retrouve à la position la plus basse possible.\n\n");
  printf("Si une colonne n'a plus de place, les joueurs ne peuvent plus placé de symboles. \nSi la grille de jeu est rempli et aucun alignement de 4 symboles identique n'a été réaliser, alors la partie recommence.\n");
  printf("ATTENTION: Ce jeu ne comporte pas la détection automatique du vainqueur (pour le moment).\n\n");

  //grid creation

  while (gameOn == 1) {
    if (turns % 2 != 0) { printf("Joueur 1 (x), c'est à toi de jouer.\nNuméro de la colonne où tu veut ajouter ton symbole: "); }
    else { printf("Joueur 2 (o), c'est à toi de jouer.\nNuméro de la colonne où tu veut ajouter ton symbole: "); }
    scanf("%d" , &column);

    //adding new symbol in column

    //if victory {}

    turns = turns + 1;

    if (turns == 42) {
      printf("Plus de place disponible, réinitialisation de la grille.\n");
      //clear grid
      turns = 0;
      printf("Voulez-vous continuez?\nEntrer '1' pour oui / Entrer '0' pour non");
      scanf("%d" , &gameOn);
    }
    printf("Fin programme\n");
    gameOn = 0;
  }

  return 0;
}
