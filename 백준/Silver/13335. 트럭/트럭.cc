#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  int n, w, l;
  cin >> n >> w >> l;

  queue<int> waiting_trucks;
  for (int i = 0; i < n; i++) {
    int weight;
    cin >> weight;
    waiting_trucks.push(weight);
  }

  queue<pair<int, int>> bridge;
  int bridge_weight = 0;
  int cur_time = 0;

  bridge.push({waiting_trucks.front(), w});
  bridge_weight += waiting_trucks.front();
  waiting_trucks.pop();
  cur_time++;

  for (; bridge.empty() == false; cur_time++) {
    int num_of_bridge_trucks = bridge.size();
    while (num_of_bridge_trucks--) {
      pair<int, int>& front_truck = bridge.front();
      bridge.pop();
      bridge.push({front_truck.first, front_truck.second - 1});
    }

    pair<int, int>& front_bridge_truck = bridge.front();
    if (front_bridge_truck.second == 0) {
      bridge_weight -= front_bridge_truck.first;
      bridge.pop();
    }

    if (!waiting_trucks.empty()) {
      int new_truck_weight = waiting_trucks.front();
      if (bridge_weight + new_truck_weight <= l) {
        waiting_trucks.pop();
        bridge.push({new_truck_weight, w});
        bridge_weight += new_truck_weight;
      }
    }
  }

  cout << cur_time << endl;
  return 0;
}