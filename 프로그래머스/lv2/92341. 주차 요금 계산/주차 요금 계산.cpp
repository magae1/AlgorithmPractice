#include <string>
#include <vector>
#include <tuple>
#include <map>
using namespace std;
const char IN = 0;
const char OUT = 1;

tuple<int, int, int> transform(string record) {
    string tmpStr = "";
    int components[3];
    int i = 0;
    for (char ch : record) {
        if (ch == ':' || ch == ' ') {
            components[i] = stoi(tmpStr);
            tmpStr.clear();
            i++;
        } 
        else {
            tmpStr += ch;
        }
    }
    components[1] += components[0] * 60;
    
    char inOrOut;
    if (tmpStr == "IN") {
        inOrOut = IN;
    }
    else {
        inOrOut = OUT;
    }
    return make_tuple(components[1], components[2], inOrOut);
}

int calCach(vector<int>& fees, int time) {
    int basicTime = fees[0];
    int basicFee = fees[1];
    int termTime = fees[2];
    int termFee = fees[3];
    
    int result = basicFee;
    time -= basicTime;
    
    if (time > 0) {
        int remainder = time % termTime;
        int addOne;
        if (remainder == 0) {
            addOne = time / termTime * termFee;
        }
        else {
            addOne = (time / termTime + 1) * termFee;
        }
        result += addOne;
    } 
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int, int> cars;
    map<int, int> recordTimes;
    for (string record : records) {
        auto tup = transform(record);
        int curTime = get<0>(tup);
        int carNum = get<1>(tup);
        char inOrOut = get<2>(tup);
        
        if (inOrOut == IN) {
            cars.insert({carNum, curTime});
        }
        else {
            auto itCar = cars.find(carNum);
            auto itTime = recordTimes.find(carNum);
            
            int parkingTime = curTime - itCar->second;
            cars.erase(itCar);
            if (itTime != recordTimes.end()) {
                itTime->second += parkingTime;
            }
            else {
                recordTimes.insert({carNum, parkingTime});
            }
        }
    }
    
    //남은 차들 정산하기
    const int LAST_TIME = 23 * 60 + 59;
    for (auto iterCar = cars.begin(); iterCar != cars.end(); iterCar++) {
        int carNum = iterCar->first;
        int parkingTime = LAST_TIME - iterCar->second;
        auto iterTime = recordTimes.find(carNum);
        if (iterTime != recordTimes.end()) {
            iterTime->second += parkingTime;            
        }
        else {
            recordTimes.insert({carNum, parkingTime});
        }        
    }
    
    vector<int> answer;
    for (auto iterBill = recordTimes.begin(); iterBill != recordTimes.end(); iterBill++) {
        int time = iterBill->second;
        answer.push_back(calCach(fees, time));
    }

    return answer;
}