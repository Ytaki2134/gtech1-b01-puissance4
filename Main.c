#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NBL 6
#define NBC 7

char* tab[NBL][NBC];

void init(void) { //grid creation
  for(int l=0; l<NBL; l++) {
    for(int c= 0; c<NBC; c++) {
      tab[l][c] = ".";
    }
  }
}

void grid(){ //grid actualisation
  printf("-------------\n");
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      printf("%s",tab[l][c]);
      printf(" ");
    }
    printf("\n");
  }
  printf("-------------\n");
  printf("1 2 3 4 5 6 7\n");
}

int gameOn = 1; //Variables affectation
int turns = 0;
int column = 0;

int main(void) { //main game

  printf(" =========================================== Welcome to the Connect 4 game! =========================================== \n");
  printf("                                              <This game is for 2 players>\n\n");
  sleep(1);
  printf("GOAL: Each player have to align 4 of his own symbols in \nthe game grid in a horizontal, vertical or diagonal way before the other player.\n\n");
  sleep(1);
  printf("HOW TO PLAY: One after the other, the players will enter the number of the column in \nwhich they want their symbol entering and go to the lowest position available.\n\n");
  printf("If a column is full, the players can't add another symbol. \nIf the game grid is full and no 4 same symbol alignment has been done, then the game restarts.\n");
  printf("WARNING: This game do not have an automatic detection of the winner (for now).\n\n");
  sleep(2);

  init();

  while (gameOn == 1) { //Player selection
    grid();
    if (turns % 2 != 0) { 
      printf("Player 2 (x), it's your turn to play.\nNumber of the column in which you want to add your symbol: "); 
    }
    else {
      printf("Player 1 (o), it's your turn to play.\nNumber of the column in which you want to add your symbol: "); 
    }
    scanf("%d" , &column);

    //adding new symbol in column
    switch (column){
      case 1:
        for(int l=5; l>=0;) {
          if (tab[l][0]=="x" || tab[l][0]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) { 
              tab[l][0]="x"; 
            }
            else { 
              tab[l][0]="o"; 
            }
          break;
          }
        }
        break;
      case 2:
        for(int l=5; l >= 0;) {
          if (tab[l][1]=="x" || tab[l][1]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) { 
              tab[l][1]="x"; 
            }
            else { 
              tab[l][1]="o"; 
            }
          break;
          }
        }
        break;
      case 3:
        for(int l=5; l>= 0;) {
          if (tab[l][2]=="x" || tab[l][2]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) { 
              tab[l][2]="x"; 
            }
            else { 
              tab[l][2]="o"; 
            }
          break;
          }
        }
        break;
      case 4:
        for(int l=5; l>= 0;) {
          if (tab[l][3]=="x" || tab[l][3]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) { 
              tab[l][3]="x"; 
            }
            else { 
              tab[l][3]="o"; 
            }
          break;
          }
        }
        break;
      case 5:
        for(int l=5; l>= 0;) {
          if (tab[l][4]=="x" || tab[l][4]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) { 
              tab[l][4]="x"; 
            }
            else { 
              tab[l][4]="o"; 
            }
          break;
          }
        }
        break;
      case 6:
        for(int l=5; l>= 0;) {
          if (tab[l][5]=="x" || tab[l][5]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) { 
              tab[l][5]="x"; 
            }
            else { 
              tab[l][5]="o"; 
            }
          break;
          }
        }
        break;
      case 7:
        for(int l=5; l >= 0;) {
          if (tab[l][6]=="x" || tab[l][6]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) { 
              tab[l][6]="x"; 
            }
            else { 
              tab[l][6]="o"; 
            }
          break;
          }
        }
        break;
      default:
        printf("Incorrect value, please try again");
        turns--;
        break;
    }

    //if victory {}

    turns++;

    if (turns == 4) {
      printf("\nNo more place available, resetting of the grid...\n");
      sleep(1); 
      init(); //grid clearance
      
      turns = 0;
      printf("Do you want to continue?\nEnter '1' for yes / Enter '0' for no\n");
      scanf("%d" , &gameOn);

      if (gameOn == 1) {
      printf("Then let's continue.\n");
      sleep(1); 
      }
      else {
      printf("See you next time on Connect 4.\n"); 
      }
    }
  }
  return 0;
}