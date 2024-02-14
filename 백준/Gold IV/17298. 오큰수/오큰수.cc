#include <iostream>
#include <stack>

int nums[1000000];

int main() {
	std::stack<int> id;	
	int N;
	int tp_num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
		if (id.empty()) {
			id.push(i);
		}
		else {
			if (nums[i] > nums[id.top()]) {
				while (!(id.empty())) {
					if (nums[id.top()] >= nums[i])
						break;
					nums[id.top()] = nums[i];
					id.pop();
				}
			}
			id.push(i);
		}
	}

	while (!(id.empty())) {
		nums[id.top()] = -1;
		id.pop();
	}
	for (int i = 0; i < N; i++)
		printf("%d ", nums[i]);
	return 0;
}