using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    long long totalPrice = 0;
    for (int i = 1; i <= count; i++) {
        totalPrice += price * i;
    }
    
    if (totalPrice > money) {
        answer = totalPrice - money;
    }
    
    return answer;
}