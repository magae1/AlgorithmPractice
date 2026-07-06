class Solution {

    static final String[] SYMBOLS = {
        "M", "D", "C", "L", "X", "V", "I"
    };

    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        int power = 1000;
        int idx = -1;
        while(power >= 1) {
            int s = num / power;
            switch(s) {
                case 4 -> {
                    sb.append(SYMBOLS[idx + 1]);
                    sb.append(SYMBOLS[idx]);
                }
                case 9 -> {
                    sb.append(SYMBOLS[idx + 1]);
                    sb.append(SYMBOLS[idx - 1]);
                }
                case 0 -> {

                }
                default -> {
                    if (s >= 5) {
                        sb.append(SYMBOLS[idx]);
                        s -= 5;
                    }
                    while(s > 0) {
                        sb.append(SYMBOLS[idx + 1]);
                        s--;
                    }
                }
            }
            num = num % power;
            power /= 10;
            idx += 2;
        }
        return sb.toString();
    }
}
