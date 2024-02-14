#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

bool func(int first, int last, int arr[], int target) {
	while (first <= last) {
		int mid = (first + last) >> 1;
		if (arr[mid] < target)
			first = mid + 1;
		else if (arr[mid] == target)
			return true;
		else
			last = mid - 1;
	}
	return false;
}

int main() {
	int N, M;
	scanf("%d", &N);
	int* contain_A = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &contain_A[i]);
	std::sort(contain_A, contain_A + N);

	scanf("%d", &M);
	while(M--){
		int a;
		scanf("%d", &a);
		printf("%d\n", func(0, N - 1, contain_A, a));
	}

	return 0;
}