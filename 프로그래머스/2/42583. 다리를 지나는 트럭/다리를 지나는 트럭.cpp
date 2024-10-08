#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_bridge_weight = 0;
    
    queue<int> truck_queue;
    for (int truck_weight : truck_weights) {
        truck_queue.push(truck_weight);
    }
    
    queue<pair<int, int>> bridge;
    bridge.push({truck_queue.front(), bridge_length});
    cur_bridge_weight += truck_queue.front();
    truck_queue.pop();
    answer += 1;
    while(!bridge.empty()) {  
        // 다리 위의 트럭들 이동
        for (int i = 0; i < bridge.size(); i++) {
            pair<int, int> front_truck = bridge.front();
            bridge.pop();
            bridge.push({front_truck.first, front_truck.second - 1});   
        }
        
        // 맨 앞의 트럭이 다리를 벗어났는지 확인
        pair<int, int> head_truck = bridge.front();
        if (head_truck.second == 0) {
            cur_bridge_weight -= head_truck.first;
            bridge.pop();
        }
        
        // 대기 중인 트럭 다리 진입
        if (!truck_queue.empty()) {
            int incoming_truck_weight = truck_queue.front();
            if (cur_bridge_weight + incoming_truck_weight <= weight) {
                truck_queue.pop();
                bridge.push({incoming_truck_weight, bridge_length});
                cur_bridge_weight += incoming_truck_weight;
            }
        }
        answer++;
    }
    
    return answer;
}