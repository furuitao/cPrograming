#include <stdio.h>
#include <string.h>
#include "readline.h"

#define MAX 2 
#define NAME_LEN 20
void insert_inventory(void);
void search_inventory(void);
void update_inventory(void);
void delete_inventory(void);
void print_inventory(void);
int find_by_number(int number);

struct inventory{
	int number;
	char name[NAME_LEN + 1];
	int quantity;
};

struct inventory data[MAX];
int data_numbers = 0;

int main(void){
	char ch;
	for(;;){
		printf("Enter operation code: ");
		ch = read_char();
		//i（插入）、s（搜索）、u（更新）、p（显示）和q（退出）
		switch(ch){
			case 'i': insert_inventory(); break;
			case 's': search_inventory(); break;
			case 'u': update_inventory(); break;
			case 'p': print_inventory(); break;
			case 'd': delete_inventory(); break;
			case 'q': return 0;
			default : printf("请输入下面的字符：i（插入）、s（搜索）、u（更新）、p（显示）、d（删除）和q（退出）\n");
		}
	}
}


/*
Enter operation code: i
Enter part number: 528
Enter part name: Disk drive
Enter quantity on hand: 10
*/
void insert_inventory(void){
	if(data_numbers == MAX){
		printf("Full.\n");
		return;
	}

	int number;
	printf("Enter part number: ");
	scanf("%d", &number);

	// 验证是否存在
	int i = find_by_number(number);
	if(i < data_numbers){
		printf("Part number %d already existed.\n", number);
		return;
	}

	data[data_numbers].number = number;
	printf("Enter part name: ");
	read_line(data[data_numbers].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &data[data_numbers].quantity);

	data_numbers++;
}
/*
Enter operation code: s
Enter part number: 528
Part name: Disk drive
Quantity on hand: 10
Enter operation code: s
Enter part number: 914
Part not found.
*/
void search_inventory(void){
	int number, i;
	printf("Enter part number: ");
	scanf("%d", &number);

	i = find_by_number(number);
	if(i < data_numbers){
		printf("Part name: %s\n", data[i].name);
		printf("Quantity on hand: %d\n", data[i].quantity);
	}else{
		printf("Part not found.\n");
	}
}
/*
Enter operation code: u
Enter part number: 528
Enter change in quantity on hand: -2
*/
void update_inventory(void){
	int number, quantity, i;
	printf("Enter part number: ");
	scanf("%d", &number);

	i = find_by_number(number);
	if(i < data_numbers){
		printf("Enter change in quantity on hand: ");
		scanf("%d", &quantity);
		data[i].quantity += quantity;
	}else{
		printf("Part not found.\n");
	}
}
/*
Enter operation code: d
Enter part number: 528
Part is deleted.
Enter operation code: d
Enter part number: 33
Part not found.
*/
void delete_inventory(void){
	int number, i;
	printf("Enter part number: ");
	scanf("%d", &number);
	
	i = find_by_number(number);
	if(i < data_numbers){
		for(; i<data_numbers; i++){
			data[i] = data[i + 1];
		}
		data_numbers--;

	}else{
		printf("Part not found.\n");
	}
}
/*
Enter operation code: p
Part Number   Part Name              Quantity on Hand
    528       Disk drive                     8
    914       Printer cable                  5
*/
void print_inventory(void){
	printf("Part Number\tPart Name\tQuantity on Hand\n");
	for (int i = 0; i < data_numbers; ++i){
		printf("%10d\t%s\t%16d\n", data[i].number, data[i].name, data[i].quantity);
	}
}

/*查询number在数组中的位置，*/
int find_by_number(int number){
	int i=0;
	for(; i<data_numbers; i++){
		if(data[i].number == number){
			break;
		}
	}
	return i;
}