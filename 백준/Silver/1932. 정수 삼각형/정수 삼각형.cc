#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    int input;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < i + 1; j++) {
            cin >> input;
            row.push_back(input);
        }
        graph[i] = row;
    }

    vector<vector<int>> paths(n);
    vector<int> p {graph[0][0]};
    paths[0] = p;
    for (int i = 1; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < i + 1; j++) {
            int left_idx = j - 1;
            int right_idx = j;

            if (left_idx < 0) {
                row.push_back(paths[i - 1][right_idx] + graph[i][j]);
                continue;
            }
            if (right_idx > i - 1) {
                row.push_back(paths[i - 1][left_idx] + graph[i][j]);
                continue;
            }
            row.push_back(max(paths[i - 1][right_idx] + graph[i][j], paths[i - 1][left_idx] + graph[i][j]));
        }
        paths[i] = row;
    }

    int result = 0;
    for (int v : paths[n - 1]) {
        result = max(result, v);
    }
    cout << result << endl;
    return 0;
}