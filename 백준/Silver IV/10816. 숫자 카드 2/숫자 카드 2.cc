#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> cards;

int func(int target) {
    auto upper = std::upper_bound(cards.begin(), cards.end(), target);
    auto lower = std::lower_bound(cards.begin(), cards.end(), target);
    if (upper != cards.end() && lower != cards.end())
        return (int)std::distance(lower, upper);
    else if (upper == cards.end() && lower != cards.end())
        return (int)std::distance(lower, cards.end());
    else if (upper != cards.end() && lower == cards.end())
        return (int)std::distance(cards.begin(), upper);
    return 0;
}

int main() {
    int N, M;
    int putin;
    int findout;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &putin);
        cards.push_back(putin);
    }
    std::sort(cards.begin(), cards.end());
    
    scanf("%d", &M);
    std::vector<int> ans(M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &findout);
        ans[i] = func(findout);
    }
    for (int b : ans)
        printf("%d ", b);
    printf("\n");
    return 0;
}
