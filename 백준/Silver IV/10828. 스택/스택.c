#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FALSE -1

void push(int);
int pop();

int stack[10000];
int size = 0;

void push(int data) {
	stack[size] = data;
	size += 1;
}

int pop() {
	int re_value = -1;
	if (stack[size - 1] != '\0') {
		re_value = stack[size - 1];
		stack[size - 1] = 0;
		size -= 1;
	}
	return re_value;
}

int main() {
	
	char buffer[20];
	int table_num = 0;
	int stack_num = 0;

	scanf("%d", &table_num);

	for (int i = 0; i < table_num; i++) {
		scanf("%s %d", buffer, &stack_num);

		if (strcmp(buffer, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(buffer, "size") == 0) {
			printf("%d\n", size);
		}
		else if (strcmp(buffer, "empty") == 0) {
			if (stack[size - 1] != '\0') {
				printf("%d\n", 0);
			}
			else {
				printf("%d\n", 1);
			}
		}
		else if (strcmp(buffer, "top") == 0) {
			if (stack[size - 1] != '\0') {
				printf("%d\n", stack[size - 1]);
			}
			else {
				printf("%d\n", -1);
			}
		}
		else if (strcmp(buffer, "push") == 0) {
			push(stack_num);
		}


	}
	return 0;
}

