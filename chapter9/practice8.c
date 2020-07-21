/*
 * 
 * 8. 编写函数模拟掷骰子的游戏（两个骰子）。第一次掷的时候，如果点数之和为7或11则获胜；如果点数之和为2、3或12则落败；其他情况下的点数之和称为“目标”，游戏继续。
 *    在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出7则落败，其他情况都忽略，游戏继续进行。
 *    每局游戏结束时，程序询问用户是否再玩一次，如果用户输入的回答不是y或Y，程序会显示胜败的次数然后终止。
 * 
 * You rolled: 8
 * Your point is 8
 * You rolled: 3
 * You rolled: 10
 * You rolled: 8
 * You win!
 * Play again? y
 * You rolled: 6
 * Your point is 6
 * You rolled: 5
 * You rolled: 12
 * You rolled: 3
 * You rolled: 7
 * You lose!
 * Play again? y
 * You rolled: 11
 * You win!
 * Play again? n
 * Wins: 2  Losses: 1
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

int roll(void);

int main(void){
	printf("Enter to roll.");

	char ch;
	int wins = 0, losses = 0;
	int goal = 0;
	int r;
	while(true){
		while(getchar() != '\n');// 只接收换行符
		r = roll();
		if(goal == 0){
			switch(r){
				case 7:
				case 11:
					wins++; 
					printf("\nYou win!"); 
					break;
				case 2:
				case 3:
				case 12:
					losses++; 
					printf("\nYou lose!"); 
					break;
				default: 
					goal = r; 
					continue; 
					break;
			}
		}else if(r == goal){
			wins++;
			printf("\nYou win!"); 
		}else if(r == 7){
			losses++;
			printf("\nYou lose!");
		}else{
			continue;
		}


		printf("\nPlay agin? ");
		while((ch = getchar()) == ' ' || ch == '\n');// 排除空格和换行符
		if(ch == 'y' || ch == 'Y'){
			goal = 0;
		}else{
			printf("\nWins: %d  Losses: %d\n", wins, losses);
			break;
		}
	}
}

int roll(void){
	srand((unsigned) time(NULL));
	int first = rand() % 6 + 1;
	int second = rand() % 6 + 1;
	printf("You rolled: %d", first + second);
	return first + second;
}