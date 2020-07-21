#include <stdio.h>
#include <string.h>

int sum(int (*f)(int), int start, int end);
int g_pow(int i);
void executeFunction(char *cmd);

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

struct {
  char *cmd_name;
  void (*cmd_pointer)(void);
} file_cmd[] =
 { {"new",             new_cmd},
   {"open",            open_cmd},
   {"close",           close_cmd},
   {"close all",       close_all_cmd},
   {"save",            save_cmd},
   {"save as",         save_as_cmd},
   {"save all",        save_all_cmd},
   {"print",           print_cmd},
   {"exit",           exit_cmd}
};


int main(void){
	printf("%d ~ %d = %d\n", 1, 10, sum(g_pow, 1, 10));	

	executeFunction("new");
	executeFunction("open");
	executeFunction("close");
	executeFunction("close all");
	executeFunction("save");
	executeFunction("save as");
	executeFunction("save all");
	executeFunction("print");
	executeFunction("exit");
}

void executeFunction(char *cmd){
	for(int i=0, len=sizeof(file_cmd)/sizeof(file_cmd[0]); i<len; i++){
		if(strcmp(file_cmd[i].cmd_name, cmd) == 0){
			file_cmd[i].cmd_pointer();
		}
	}
}

void new_cmd(void){
	printf("new_cmd function.\n");
}
void open_cmd(void){
	printf("open_cmd function.\n");
}
void close_cmd(void){
	printf("close_cmd function.\n");
}
void close_all_cmd(void){
	printf("close_all_cmd function.\n");
}
void save_cmd(void){
	printf("save_cmd function.\n");
}
void save_as_cmd(void){
	printf("save_as_cmd function.\n");
}
void save_all_cmd(void){
	printf("save_all_cmd function.\n");
}
void print_cmd(void){
	printf("print_cmd function.\n");
}
void exit_cmd(void){
	printf("exit_cmd function.\n");
}

int sum(int (*f)(int), int start, int end){
	int result = 0;
	for(; start<=end; start++){
		result += f(start);
	}
	return result;
}

int g_pow(int i){
	return i * i;
}