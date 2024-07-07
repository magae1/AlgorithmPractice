class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int num_of_drinks = 0, num_of_empty_bottles = 0;
        while(true) {
            num_of_empty_bottles += numBottles;
            num_of_drinks += numBottles;
            if (num_of_empty_bottles < numExchange) {
                break;
            }

            numBottles = num_of_empty_bottles / numExchange;
            num_of_empty_bottles = num_of_empty_bottles % numExchange;
        }
        return num_of_drinks;
    }
};