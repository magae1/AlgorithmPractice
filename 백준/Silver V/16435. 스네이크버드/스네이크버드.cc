#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numOfFruits, snakeLength;
    cin >> numOfFruits >> snakeLength;

    int currentSnakeLength = snakeLength;

    vector<int> fruitHeights(numOfFruits);
    for (int i = 0; i < numOfFruits; i++) {
        std::cin >> fruitHeights[i];
    }

    sort(fruitHeights.begin(), fruitHeights.end());

    for (auto it = fruitHeights.begin(); it != fruitHeights.end(); it++) {
        if (currentSnakeLength >= *it) {
            currentSnakeLength++;
        } else {
            break;
        }
    }
    cout << currentSnakeLength;
}
