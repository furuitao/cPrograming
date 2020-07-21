/*Deals a random hand of cards*/
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define NUM_SUITS 4
#define NUM_RANKS 13
int main(void){
	bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
	int num_cards, rank, suit;
	int n = 0;
	const char rank_code[] = {'2','3','4','5','6','7','8','9','t','J','Q','K','A'};
  	const char suit_code[] = {'c','d','h','s'};

  	srand((unsigned) time(NULL));
  	printf("Enter number of cards in hand: ");
  	scanf("%d", &num_cards);

  	printf("Your hand: ");
  	while(num_cards > 0){
  		n ++;
  		suit = rand() % NUM_SUITS;
  		rank = rand() % NUM_RANKS;
  		if(!in_hand[suit][rank]){
  			in_hand[suit][rank] = true;
  			num_cards --;
  			printf(" %c%c", rank_code[rank], suit_code[suit]);
  		}
  	}

  	printf("\n");
  	printf("%d\n", n);// 统计计算次数
  	return 0;
}