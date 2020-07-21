#include "stdio.h"
#include "string.h"

void get_extension(const char *file_name, char *extension);

int main(void){
	char s[10];
	*s = 0;
	printf("%s\n", s);
	char str[50];
	printf("%s\n", str);
	strcpy(str, "tire-bouchon");
	printf("%s\n", str);
	strcpy(&str[4], "d-or-wi");
	printf("%s\n", str);
	strcat(str, "red?");
	printf("%s\n", str);


	char s1[50],s2[50];
	strcpy(s1, "computer");
	strcpy(s2, "science");
	if (strcmp(s1, s2) < 0)
	  strcat(s1, s2);
	else
	  strcat(s2, s1);
	s1[strlen(s1)-6] = '\0';
	printf("%s\n", s1);

	char ss1[50] = "aaab.txt";
	char extension[10];
	get_extension(ss1, extension);
	printf("%s\n", extension);
}

void get_extension(const char *file_name, char *extension){
	int l = strlen(file_name) - 1;
	for(; l >= 0; l--){
		if(*(file_name + l) == '.'){
			break;
		}
	}
	printf("%d\n", l);
	if(l == -1){
		strcpy(extension, "");
	}else{
		strcpy(extension, &file_name[l + 1]);
	}
}
