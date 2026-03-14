#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
  int valid = 1;
  int playerChoice,computerChoice;
  do{
  srand(time(NULL));
  printf("\n***ROCK-PAPER-SCISSOR***\n");
  printf("1.🪨\n2.🧻\n3.✂️\n(4-for quit)\nEnter your choice: ");
  scanf("%d",&playerChoice);
  if (playerChoice == 4) {printf("Thank you.\n"); break;}
  if (playerChoice > 4 ) {printf("Invalid Choice.\n"); break;}
  computerChoice = ((rand() % 3) + 1);
  switch(computerChoice){
  case 1: printf("Computer choice:🪨\n"); break;
  case 2: printf("Computer choice:🧻\n"); break;
  case 3: printf("Computer choice:✂️\n"); break;
  }
  if (playerChoice == computerChoice) printf("It's a tie..!\n");
  else if (playerChoice == 1 && computerChoice == 2 || playerChoice == 2 && computerChoice == 3 || playerChoice == 3 && computerChoice == 1) printf("You lose...:(\n");
  else printf("You Won!!\n");
  }while(playerChoice!=4);
  return 0;
}
  
  
