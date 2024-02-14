#include <iostream>

int people[50][3];

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> people[i][0] >> people[i][1];

    for (int i = 0; i < N; i++) {
        int inputrank = 1;
        int weight = people[i][0];
        int height = people[i][1];
        for (int j = 0; j < N; j++) {
            if (people[j][0] > weight && people[j][1] > height)
                inputrank++;
        }
        people[i][2] = inputrank;
    }
    for (int i = 0; i < N; i++)
        std::cout << people[i][2] << ' ';
    return 0;
}