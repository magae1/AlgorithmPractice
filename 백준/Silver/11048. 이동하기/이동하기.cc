#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > directions(3);
    directions[0] = make_pair(1, 0);
    directions[1] = make_pair(0, 1);
    directions[2] = make_pair(1, 1);
    vector<vector<int> > maze(n, vector<int>(m));
    vector<vector<int> > max_candies(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    max_candies[0][0] = maze[0][0];
    int total = n + m - 1;
    for (int t = 0; t < total; t++) {
        for (int r = 0; r <= t; r++) {
            int c = t - r;
            for (pair<int, int>& d: directions) {
                int next_r = r + d.first;
                int next_c = c + d.second;
                if (next_r >= n || next_c >= m) {
                    continue;
                }

                int new_candies = max_candies[r][c] + maze[next_r][next_c];
                max_candies[next_r][next_c] = max(max_candies[next_r][next_c], new_candies);
            }
        }
    }

    cout << max_candies[n - 1][m - 1] << endl;
    return 0;
}