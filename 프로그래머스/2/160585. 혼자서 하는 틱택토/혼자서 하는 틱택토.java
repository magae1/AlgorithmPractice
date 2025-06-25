class Solution {
    
    private static final int MAX_LEN = 3;
    private static final char O = 'O';
    private static final char X = 'X';
    private static final char EMPTY = '.';
    
    public int solution(String[] board) {
        int sumOfO = 0;
        int sumOfX = 0;
        
        for (String b : board) {
            for (int i = 0; i < MAX_LEN; i++) {
                char ch = b.charAt(i);
                if (ch == O) {
                    sumOfO += 1;
                } else if (ch == X) {
                    sumOfX += 1;
                }
            }
        }
        
        if (sumOfX != sumOfO - 1 && sumOfX != sumOfO) {
            return 0;
        }
        
        int countOfOWin = 0;
        int countOfXWin = 0;
        
        int[] rowCounts = calculateRow(board);
        countOfOWin += rowCounts[0];
        countOfXWin += rowCounts[1];
        int[] colCounts = calculateCol(board);
        countOfOWin += colCounts[0];
        countOfXWin += colCounts[1];
        int[] crossCounts = calculateCross(board);
        countOfOWin += crossCounts[0];
        countOfXWin += crossCounts[1];
        
        if (countOfOWin > 0 && countOfXWin > 0) {
            return 0;
        } else if (countOfOWin > countOfXWin) {
            return (sumOfO == sumOfX + 1 ? 1 : 0);
        } else if (countOfOWin < countOfXWin) {
            return (sumOfX == sumOfO ? 1 : 0);
        }
        
        return 1;
    }
    
    private int[] calculateRow(String[] board) {
        int[] result = new int[2];
        for (String c : board) {
            char ch = c.charAt(0);
            if (ch == EMPTY) {
                continue;
            }
            boolean isMatched = true;
            for (int i = 1; i < MAX_LEN; i++) {
                if (ch != c.charAt(i)) {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched) {
                if (ch == O) {
                    result[0] += 1;
                } else {
                    result[1] += 1;
                }
            }
        }
        return result;
    }
    
    private int[] calculateCol(String[] board) {
        int[] result = new int[2];
        
        for (int j = 0; j < MAX_LEN; j++) {
            char ch = board[0].charAt(j);
            if (ch == EMPTY) {
                continue;
            }
            
            boolean isMatched = true;
            for (int i = 1; i < MAX_LEN; i++) {
                char curCh = board[i].charAt(j);
                if (ch != curCh) {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched) {
                if (ch == O) {
                    result[0] += 1;
                } else {
                    result[1] += 1;
                }
            }
        }
        return result;
    }
    
    private int[] calculateCross(String[] board) {
        int[] result = new int[2];
        
        char ch = board[1].charAt(1);
        if (ch == EMPTY) {
            return result;
        }
        
        if (board[0].charAt(0) == ch && board[2].charAt(2) == ch) {
            if (ch == O) {
                result[0] += 1;
            } else {
                result[1] += 1;
            }
        }
        
        if (board[0].charAt(2) == ch && board[2].charAt(0) == ch) {
            if (ch == O) {
                result[0] += 1;
            } else {
                result[1] += 1;
            }
        }
        
        return result;
    }
    
}