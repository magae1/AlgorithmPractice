import java.util.*;

class Solution {
    class Position {
        public final int i;
        public final int j;
        
        public Position(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    
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
    
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        
        boolean[][] isVisited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 0 || isVisited[i][j]) continue;
                int size = bfs(new Position(i, j), m, n, picture, isVisited);
                maxSizeOfOneArea = Math.max(size, maxSizeOfOneArea);
                numberOfArea += 1;
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    
    private int bfs(Position pos, int m, int n, int[][] picture, boolean[][] isVisited) {
        Queue<Position> qu = new LinkedList<>();
        qu.add(pos);
        int color = picture[pos.i][pos.j];
        int sizeOfArea = 0;
        
        while(!qu.isEmpty()) {
            Position curPos = qu.poll();
            
            for (Direction d : Direction.values()) {
                Position nextPos = new Position(curPos.i + d.i, curPos.j + d.j);
                if (nextPos.i < 0 || nextPos.i >= m || nextPos.j < 0 || nextPos.j >= n) continue;
                if (picture[nextPos.i][nextPos.j] != color) continue;
                if (isVisited[nextPos.i][nextPos.j]) continue;
                
                qu.add(nextPos);
                isVisited[nextPos.i][nextPos.j] = true;
                sizeOfArea += 1;
            }
        }
        
        return sizeOfArea;
    }
}