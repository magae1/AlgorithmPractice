import java.util.*;

class Solution {    
    enum Direction {
        NORTH(-1, 0),
        SOUTH(1, 0),
        WEST(0, -1),
        EAST(0, 1);
            
        public final int i;
        public final int j;
        
        Direction(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    
    class Position {
        public final int i;
        public final int j;
        
        Position(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    
    public int solution(String[] storage, String[] requests) {
        int n = storage.length;
        int m = storage[0].length();
        boolean[][] isFilled = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(isFilled[i], true);
        }
        
        boolean[][] accessible = new boolean[n][m];    
        Arrays.fill(accessible[0], true);
        Arrays.fill(accessible[n - 1], true);
        for (int i = 0; i < n; i++) {
            accessible[i][0] = true;
            accessible[i][m - 1] = true;
        }
        
        Queue<Position> qu = new LinkedList<>();
        int answer = n * m;
        for (String req : requests) {       
            char ch = req.charAt(0);
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i].charAt(j) != ch) continue;
                    if (!isFilled[i][j]) continue;
                    if (req.length() == 1 && !accessible[i][j]) continue;
                    
                    isFilled[i][j] = false;
                    answer -= 1;
                    
                    if (accessible[i][j]) {
                        qu.add(new Position(i, j));
                    }
                }
            }
            
            while(!qu.isEmpty()) {
                Position curPos = qu.poll();
                for (Direction d : Direction.values()) {
                    Position nextPos = new Position(curPos.i + d.i, curPos.j + d.j);
                    if (nextPos.i < 0 || nextPos.j < 0 || nextPos.i >= n || nextPos.j >= m) continue;
                    if (accessible[nextPos.i][nextPos.j]) continue;
                    
                    accessible[nextPos.i][nextPos.j] = true;
                    if (!isFilled[nextPos.i][nextPos.j]) {
                        qu.add(nextPos);    
                    }
                }
            }
        }
 
        return answer;
    }
    
}