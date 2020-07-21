/*
 * 1. 编写程序找出一组单词中“最小”单词和“最大”单词。用户输入单词后，程序根据字典顺序决定排在最前面和最后面的单词。当用户输入4个字母的单词时，程序停止读入。假设所有单词都不超过20个字母。程序会话如下：
 * 
 * Enter word:  dog
 * Enter word:  zebra
 * Enter word:  rabbit
 * Enter word:  catfish
 * Enter word:  walrus
 * Enter word:  cat
 * Enter word:  fish
 * Smallest word: cat
 * Largest word: zebra
 * 
 */
 #include "stdio.h"
 #include "string.h"
 int main(void){
 	char largest[20], smallest[20], str[20];
 	do{
 		printf("Enter word: ");
 		gets(str);
		if(!*largest){
			strcpy(smallest, str);
			strcpy(largest, str);
		}else if(strcmp(largest, str) < 0){
			strcpy(largest, str);
		}else if(strcmp(smallest, str) > 0){
			strcpy(smallest, str);
		}
 	}while(strlen(str) != 4);
 	
 	printf("Smallest word: %s\n", smallest);
 	printf("Largest word: %s\n", largest);
 }