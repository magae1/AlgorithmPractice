#include <iostream>
#include <cstring>
using namespace std;

int queue[2000000];
int back_size = 0;
int front_size = 0;

void Push(int x) {
	queue[back_size] = x;
	back_size++;
}

int Pop() {
	if (queue[front_size] == 0)
		return -1;
	int result = queue[front_size];
	queue[front_size] = 0;
	front_size++;
	return result;
}

int Size() {
	return (back_size - front_size);
}

int Empty() {
	if (back_size == front_size)
		return 1;
	else
		return 0;
}

int Front() {
	if (queue[front_size] == 0)
		return -1;
	return queue[front_size];
}

int Back() {
	if (queue[back_size - 1] == 0)
		return -1;
	return queue[back_size - 1];
}

int main(void) {
	int N;
	scanf("%d", &N);
	while (N--) {
		char ch[6];
		scanf("%s", ch);
		if (strcmp(ch, "push") == 0) {
			int num;
			scanf("%d", &num);
			Push(num);
		}
		else if (strcmp(ch, "pop") == 0) {
			printf("%d\n", Pop());
		}
		else if (strcmp(ch, "size") == 0) {
			printf("%d\n", Size());
		}
		else if (strcmp(ch, "empty") == 0) {
			printf("%d\n", Empty());
		}
		else if (strcmp(ch, "front") == 0) {
			printf("%d\n", Front());
		}
		else if (strcmp(ch, "back") == 0) {
			printf("%d\n", Back());
		}
	}

	return 0;
}
