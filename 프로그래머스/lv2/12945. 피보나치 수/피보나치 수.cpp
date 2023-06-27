using namespace std;

int num[100001];

int func(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    
    if (num[n] == 0) {
        num[n] = (func(n - 1) + func(n - 2)) % 1234567;
    }
    return num[n];
}


int solution(int n) {
    int answer = func(n);
    return answer;
}