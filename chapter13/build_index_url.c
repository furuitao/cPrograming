/*
 * 13. 编写下面的函数：
 * void build_index_url(const char *domain, char *index_url);
 * domain指向包含因特网域名的字符串，例如"knking.com"。函数应在该字符串的前面加上"http://www."，在后面加上"/index.html"，并把结果存储到index_url指向的字符串中。
 *（在这个例子中，结果为"http://www.knking.com/index.html * "。）可以假定index_url所指向的变量长度足以装下整个字符串。在函数中使用strcat函数和strcpy函数，使其尽可能简单。
 * 
 */
#include "stdio.h"
#include "string.h"
void build_index_url(const char *domain, char *index_url);
int main(void){
	char domain[20] = "knking.com";
	char index_url[100] = "/index.html";
	build_index_url(domain, index_url);
	printf("%s\n", index_url);
}

void build_index_url(const char *domain, char *index_url){
	char temp[strlen(index_url) + 1];
	strcpy(temp, index_url);
	strcpy(index_url, "http://www.");
	strcat(index_url, domain);
	strcat(index_url, temp);
}