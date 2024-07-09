class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_waiting_time = 0;

        int cur_time = 0;
        for (auto iter = customers.begin(); iter != customers.end(); iter++) {
            int arrive_time = (*iter)[0];
            int waiting_time = (*iter)[1];
            if (cur_time < arrive_time) {
                cur_time = arrive_time;
            }

            int added_waiting_time = cur_time - arrive_time;
            total_waiting_time += (double)(added_waiting_time + waiting_time);
            cur_time += waiting_time;
        }

        return total_waiting_time / customers.size();
    }
};