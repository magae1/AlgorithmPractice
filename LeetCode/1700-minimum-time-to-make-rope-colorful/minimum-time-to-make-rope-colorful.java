class Solution {
    public int minCost(String colors, int[] neededTime) {
        int totalCost = 0;
        Calculator cal = new Calculator();

        char prevColor = ' ';
        for (int i = 0; i < neededTime.length; i++) {
            char currentColor = colors.charAt(i);

            if (prevColor != currentColor) {
                totalCost += cal.getRestTime();
                cal.reset();
            }
            prevColor = currentColor;
            cal.addTime(neededTime[i]);
        }

        totalCost += cal.getRestTime();
        return totalCost;
    }

    class Calculator {
        static final int MIN_TIME_VALUE = 0;
        private int totalTime = 0;
        private int maxTime = MIN_TIME_VALUE;
        private boolean isCalculating = false;

        void addTime(int time) {
            this.totalTime += time;
            this.maxTime = Math.max(this.maxTime, time);
        }

        int getRestTime() {
            return this.totalTime - this.maxTime;
        }

        boolean getIsCalculating() {
            return this.isCalculating;
        }

        void setIsCalculating(boolean isCalculating) {
            this.isCalculating = isCalculating;
        }

        void reset() {
            this.totalTime = 0;
            this.maxTime = MIN_TIME_VALUE;
        }
    }


}