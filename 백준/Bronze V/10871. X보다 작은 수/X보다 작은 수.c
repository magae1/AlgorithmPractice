#include<stdio.h>

int main() {
	int n, x;	
	scanf("%d %d", &n, &x);

	int arr[10000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int j = 0; j < n; j++) {
		if (arr[j] < x)
			printf("%d ", arr[j]);
	}

	return 0;
}