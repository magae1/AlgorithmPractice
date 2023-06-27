#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    int serialSize = 1;
    while(true) {
        int rest = 0;
        for (int i = 0; i < serialSize; i++) {
            rest += i;
        }
        
        int subN = n - rest;
        
        if (rest + serialSize > n) {
            break;
        }
            
        if (subN % serialSize == 0) {
            answer++;
        }
        serialSize++;
    }
    
    return answer;
}