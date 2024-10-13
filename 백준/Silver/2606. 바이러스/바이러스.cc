#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Computer {
private:
    bool is_visited;
    vector<Computer*> adjust_computers;

public:
    Computer() {
        this->is_visited = false;
    }

    void add_adjust_computer(Computer* computer) {
        this->adjust_computers.push_back(computer);
    }

    vector<Computer*>& get_adjust_computers() {
        return this->adjust_computers;
    }

    bool get_is_visited() {
        return this->is_visited;
    }

    void set_is_visited(bool is_visited) {
        this->is_visited = is_visited;
    }
};

int main() {
    int n, m;
    cin >> n;
    vector<Computer> computers = vector<Computer>(n + 1);

    cin >> m;
    while(m--) {
        int fst, sec;
        cin >> fst >> sec;
        computers[fst].add_adjust_computer(&computers[sec]);
        computers[sec].add_adjust_computer(&computers[fst]);
    }

    int result = 0;
    deque<Computer*> deq;
    computers[1].set_is_visited(true);
    deq.push_back(&computers[1]);
    while(!deq.empty()) {
        Computer* cur_com = deq.front();
        deq.pop_front();
        for (Computer* adjust_com : cur_com->get_adjust_computers()) {
            if (!adjust_com->get_is_visited()) {
                adjust_com->set_is_visited(true);
                deq.push_back(adjust_com);
                result++;
            }
        }
    }


    cout << result << endl;
    return 0;
}