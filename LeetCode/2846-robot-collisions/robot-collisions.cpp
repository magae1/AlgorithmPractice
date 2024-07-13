class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<tuple<int, int, char, int>> robots;
        for (int i = 0; i < positions.size(); i++) {
            robots.push_back({positions[i], healths[i], directions[i], i + 1});
        }

        sort(robots.begin(), robots.end(),
             [](tuple<int, int, char, int> a, tuple<int, int, char, int> b) {
                 return get<0>(a) < get<0>(b);
             });

        vector<pair<int, int>> remain_robots;
        stack<pair<int, int>> stk;
        for (auto robot : robots) {
            pair<int, int> right_robot{get<1>(robot), get<3>(robot)};
            if (get<2>(robot) == 'R') {
                stk.push(right_robot);
            } else {
                while (!stk.empty()) {
                    auto left_robot = stk.top();
                    stk.pop();
                    if (left_robot.first > right_robot.first) {
                        left_robot.first = left_robot.first - 1;
                        stk.push(left_robot);
                        right_robot.first = 0;
                        break;
                    } else if (left_robot.first == right_robot.first) {
                        right_robot.first = 0;
                        break;
                    } else {
                        right_robot.first = right_robot.first - 1;
                    }
                }
                if (right_robot.first > 0) {
                    remain_robots.push_back(right_robot);
                }
            }
        }
        while (!stk.empty()) {
            remain_robots.push_back(stk.top());
            stk.pop();
        }
        sort(remain_robots.begin(), remain_robots.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 return a.second < b.second;
             });

        vector<int> result;
        for (auto remain : remain_robots) {
            result.push_back(remain.first);
        }
        return result;
    }
};