#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;


int solution(int n, vector<vector<int>> wires) {
    vector<bool> node(n+1);
    vector<vector<bool>> edge(n+1, vector<bool>(n+1));
    
    for (auto wire : wires) {
        int fstNode = wire[0];
        int secNode = wire[1];
        
        edge[fstNode][secNode] = true;
        edge[secNode][fstNode] = true;        
    }

    int answer = INT_MAX;
    for (auto wire : wires) {
        edge[wire[0]][wire[1]] = false;
        edge[wire[1]][wire[0]] = false;
        
        int numOfNode[2] = {0, };
        
        for (int i = 0; i < 2; i++) {
            queue<int> qu;
            qu.push(wire[i]);
            while(!qu.empty()) {
                int curNode = qu.front();
                node[curNode] = true;
                numOfNode[i]++;
                for (int j = 1; j <= n; j++) {
                    if (edge[curNode][j] && !node[j]) {
                        qu.push(j);
                    }
                }
                qu.pop();
            }
        }
        
        answer = min(answer, abs(numOfNode[0] - numOfNode[1]));
        edge[wire[0]][wire[1]] = true;
        edge[wire[1]][wire[0]] = true;
        for (int b = 1; b <= n; b++) {
            node[b] = false;
        }
    }
    

    return answer;
}