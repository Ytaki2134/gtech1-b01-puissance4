#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define NBL 6
#define NBC 7

char* tab[NBL][NBC];

void init(void) { //Grid creation
  for(int l=0; l<NBL; l++) {
    for(int c= 0; c<NBC; c++) {
      tab[l][c] = ".";
    }
  }
}

void grid(){ //Grid actualisation
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

void flushstdin() { //Buffer clean
  int c;
  while((c = getchar()) != '\n' && c != EOF) {
  }
}

int gameOn = 1; //Variables affectation
int turns = 0;
int colnum = 0;
int col_idx;

int main(void) { //Main game

  printf(" =========================================== Welcome to the Connect 4 game! =========================================== \n"); //Intro text
  printf("                                              <This game is for 2 players>\n\n");
  sleep(1);
  printf("GOAL: Each player have to align 4 of his own symbols in \nthe game grid in a horizontal, vertical or diagonal way before the other player.\n\n");
  sleep(1);
  printf("HOW TO PLAY: One after the other, the players will enter the number of the column in \nwhich they want their symbol entering and go to the lowest position available.\n\n");
  printf("If a column is full, the players can't add another symbol. \nIf the game grid is full and no 4 same symbol alignment has been done, then the game restarts.\n\n");
  sleep(2);

  init();

  while (gameOn == 1) { //Player selection
    grid();

    do{
      if (turns % 2 != 0) {
        printf("Player 2 (x), it's your turn to play.\nNumber of the column in which you want to add your symbol: ");
      }
      else {
        printf("Player 1 (o), it's your turn to play.\nNumber of the column in which you want to add your symbol: ");
      }
      int nbmatch = scanf("%d" , &colnum);
      if (nbmatch!=1){ // Test 1: nbmatch != 1 --> continue / Check if only a single value is entered
        printf("Incorrect value, please try again.\n");
        sleep(1);
        flushstdin();
        continue;
      }
      int col_idx = colnum-1;
      if (col_idx<=-1 || col_idx>=7) { // Test 2: tester col_idx --> continue / Check if the value is between 1 and 7
        printf("Incorrect value, please try again.\n");
        sleep(1);
        flushstdin();
        continue;
      }
      if (tab[0][col_idx]=="x" || tab[0][col_idx]=="o"){  // Test 3: colonne col_idx n'est pas pleine --> continue / Check if the column is full
        printf("Selected column is full, please try another one.\n");
        colnum=0;
        sleep(1);
        flushstdin();
        continue;
      }
      else{
        for(int l=5; l>=0;) { //Adding new symbol in column
          if (tab[l][col_idx]=="x" || tab[l][col_idx]=="o") {
            l = l-1;
            continue;
          }
          else {
            if (turns % 2 != 0) {
              tab[l][col_idx]="x";
            }
            else {
              tab[l][col_idx]="o"; 
            }
          flushstdin();
          break;
          }
        break;
        }
      break;
      }
    break;
    }
    while(1);

    turns++;

    if (turns == 42) { //Check if the grid is full ,and if so, resets it
      printf("\nNo more place available, resetting of the grid...\n");
      sleep(1);
      init();
      turns = 0;

      do{ //Asks the players if they want to continue playing
        printf("Do you want to continue?\nEnter '1' for yes / Enter '0' for no\n");
        int nbmatch = scanf("%d" , &gameOn);
        if (nbmatch!=1){ // Test 1: nbmatch != 1 --> continue / Check if only a single value is entered
          printf("Incorrect value, please try again.\n");
          sleep(1);
          flushstdin();
          continue;
        }
        if (gameOn<=-1 || gameOn>=2) { // Test 2: tester col_idx --> continue / Check if the value is between 0 and 1
          printf("Incorrect value, please try again.\n");
          sleep(1);
          flushstdin();
          continue;
        }
        else {
          break;
        }
      }
    while(1);

      if (gameOn == 1) { //They want to continue
      printf("Then let's continue.\n");
      sleep(1);
      }
      else { //They want to quit playing
      printf("See you next time on Connect 4.\n");
      sleep(1);
      }
    }
  }
  return 0;
}