#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int redcost;
    int greencost;
    int bluecost;
}ColorCost;

int main() {
    int N;
    cin >> N;
    vector<ColorCost> ColoringCosts(N);
    vector<int> RedHouseCost(N);
    vector<int> GreenHouseCost(N);
    vector<int> BlueHouseCost(N);
    for (int i = 0; i < N; i++)
        cin >> ColoringCosts[i].redcost >> ColoringCosts[i].greencost >> ColoringCosts[i].bluecost;
    RedHouseCost[0] = ColoringCosts[0].redcost;
    GreenHouseCost[0] = ColoringCosts[0].greencost;
    BlueHouseCost[0] = ColoringCosts[0].bluecost;
    
    for (int i = 1; i < N; i++) {
        RedHouseCost[i] = (GreenHouseCost[i-1] > BlueHouseCost[i-1] ? BlueHouseCost[i-1] : GreenHouseCost[i-1]) + ColoringCosts[i].redcost;
        GreenHouseCost[i] = (RedHouseCost[i-1] > BlueHouseCost[i-1] ? BlueHouseCost[i-1] : RedHouseCost[i-1]) + ColoringCosts[i].greencost;
        BlueHouseCost[i] = (RedHouseCost[i-1] > GreenHouseCost[i-1] ? GreenHouseCost[i-1] : RedHouseCost[i-1]) + ColoringCosts[i].bluecost;
    }
    int result = (RedHouseCost[N-1] > GreenHouseCost[N-1] ? GreenHouseCost[N-1] : RedHouseCost[N-1]);
    result = (result > BlueHouseCost[N-1] ? BlueHouseCost[N-1] : result);
    
    cout << result << endl;
    return 0;
}
