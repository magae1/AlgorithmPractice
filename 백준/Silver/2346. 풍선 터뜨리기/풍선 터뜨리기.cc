#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> result;
    vector<int> nums(n);
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums[i] = num;
        deq.push_back(i);
    }

    while(!deq.empty()) {
        int front_idx = deq.front();
        deq.pop_front();
        int front_num = nums[front_idx];
        result.push_back(front_idx + 1);

        if (front_num > 0) {
            for (int i = 1; i < front_num; i++) {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        } else {
            for (int i = 0; i > front_num; i--) {
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}