/*
 * 9.编写程序，生成一种贯穿10×10字符数组（初始时全为字符'.'）的“随机步法”。程序必须随机地从一个元素“走到”另一个元素，每次都向上、向下、向左或向右移动一个元素位置。已访问过的元素按访问顺序用字母A到Z进行标记。
 */
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"

#define X 10
#define Y 10
int main(void){
	char table[X][Y];
	int step[4] = {false};
	int r,s=1,x=0,y=0;
	
	// 将每个元素初始化为.
	for(int i=0; i<X; i++){
		for(int j=0; j<Y; j++){
			table[i][j] = '.';
		}
	}

	srand((unsigned)time(NULL));
	table[x][y] = 'A';
	while(true){
		r = rand() % 4;
		bool match = false;
		// printf("%d\n", r);
		if(!step[r]){
			if(r == 0 && x - 1 >=0 && table[x - 1][y] == '.'){// 向左为空
				x--;
				match = true;
			}else if(r == 1 && y + 1 < Y && table[x][y + 1] == '.'){// 向下为空
				y++;
				match = true;
			}else if(r == 2 && x + 1 < X && table[x + 1][y] == '.'){// 向右为空
				x++;
				match = true;
			}else if(r == 3 && y - 1 >= 0 && table[x][y - 1] == '.'){// 向上为空
				y--;
				match = true;
			}else{
				step[r] = true;
			}
		}
		if(match){//清空step
			table[x][y] = (char)('A' + s++);// 设置元素值
			for(int i=0; i<4; i++){
				step[i] = false;
			}
		 	if(table[x][y] == 'Z'){//已经跑完全部字符退出程序
				break;
			}
		}else{
			bool all = true;
			for(int i=0; i<4; i++){
				if(!step[i]){
					all = false;// 继续尝试
				}
			}
			if(all){
				break;// 已经全部尝试，退出程序	
			}
		}
	}

	for(int i=0; i<X; i++){
		for(int j=0; j<Y; j++){
			printf("%c\t", table[i][j]);
		}
		printf("\n");
	}

	return 0;
}