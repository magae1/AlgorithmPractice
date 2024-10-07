#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> flags (n + 1, false);
    vector<vector<bool>> edges(n + 1, vector<bool>(n + 1, false));
    int start_num, end_num;
    cin >> start_num >> end_num;

    int num_of_edges;
    cin >> num_of_edges;
    while(num_of_edges--) {
        int s, d;
        cin >> s >> d;
        edges[s][d] = true;
        edges[d][s] = true;
    }

    int result = -1;
    queue<pair<int, int>> qu;
    qu.push({start_num, 0});
    while(!qu.empty()) {
        pair<int, int> cur_state = qu.front();
        int cur_idx = cur_state.first;
        int cur_depth = cur_state.second;
        qu.pop();

        if (cur_idx == end_num) {
            result = cur_depth;
            break;
        }

        flags[cur_idx] = true;
        for (int i = 1; i <= n; i++) {
            if (edges[cur_idx][i] && !flags[i]) {
                qu.push({i, cur_depth + 1});
            }
        }
    }

    cout << result << endl;
    return 0;
}