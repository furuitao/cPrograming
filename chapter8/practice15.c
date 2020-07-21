/*
 * 15. 已知的最古老的一种加密技术是凯撒加密（得名于Julius Caesar）。该方法把一条消息中的每个字母用字母表中固定距离之后的那个字母来替代。
 * Enter message to be encrypted: Go ahead, make my day.
 * Enter shift amount (1-25): 3
 * Encrypted message: Jr dkhdg, pdnh pb gdb.
 *
 */
#include "stdio.h"
#define CHAR_LEN 5
int main(void){
	int dist;
	char in_char[CHAR_LEN];
	char ch;

	printf("Enter message to be encrypted: ");
	int i=0;
	while(i < CHAR_LEN && (ch = getchar()) != '\n'){//只支持CHAR_LEN个字符
		in_char[i++] = ch;
	}
	while(i >= CHAR_LEN && getchar() != '\n');//如果大于CHAR_LEN字符，清空标准输入

	printf("Enter shift amount (1-25): ");
	scanf("%d", &dist);
	printf("Encrypted message: ");
	for(int j=0; j<i; j++){
		ch = in_char[j];
		if(ch >= 'A' && ch <= 'Z'){// 大写字母加密
			printf("%c", (ch - 'A' + dist) % 26 + 'A');
		}else if(ch >= 'a' && ch <= 'z'){// 小写字母加密
			printf("%c", (ch - 'a' + dist) % 26 + 'a');
		}else{//其他字符原样输出
			printf("%c", ch);
		}
	}
	printf("\n");

	return 0;
}