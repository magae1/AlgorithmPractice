#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<pair<int, int>> stock_stk;
    
    for (int i = 0; i < prices.size(); i++) {   
        int cur_price = prices[i];
        
        while(!stock_stk.empty()) {
            pair<int, int> prev_stock = stock_stk.top();
            if (prev_stock.second <= cur_price) {
                break;
            }
            
            answer[prev_stock.first] = (i - prev_stock.first);
            stock_stk.pop();
        }
        stock_stk.push({i, cur_price});
    }
    
    while(!stock_stk.empty()) {
        pair<int, int> cur_stock = stock_stk.top();
        stock_stk.pop();
        answer[cur_stock.first] = prices.size() - cur_stock.first - 1;
    }
    
    return answer;
}
