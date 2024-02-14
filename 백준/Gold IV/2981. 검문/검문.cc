#include <iostream>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int func(size_t* ch, size_t M) {
    size_t i = 1;
    int ch_size = 0;
    while(i * i < M) {
        if (M % i == 0){
            ch[ch_size] = i;
            ch_size++;
        }
        i++;
    }
    if (i * i == M) {
        ch[ch_size] = i;
        for (int j = 1; j <= ch_size; j++)
            ch[ch_size + j] = M / ch[ch_size - j];
        return 2 * ch_size + 1;
    }
    else {
        for (int j = 0; j < ch_size; j++)
            ch[ch_size + j] = M / ch[ch_size - j - 1];
        return 2 * ch_size;
    }
}

int main() {
    int N;
    size_t nums[100];
    size_t dix[10000];
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> nums[i];
    qsort(nums, N, sizeof(size_t), cmp);
    for (int i = 1; i < N; i++)
        nums[i] -= nums[0];
    
    int ans = func(dix, nums[1]);
    for (int i = 1; i < ans; i++) {
        bool checker = true;
        for (int j = 1; j < N; j++) {
            if (nums[j] % dix[i] != 0) {
                checker = false;
                break;
            }
        }
        if (checker)
            printf("%lu ", dix[i]);
    }
    return 0;
}
