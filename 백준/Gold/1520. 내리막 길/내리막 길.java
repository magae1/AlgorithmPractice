import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Position {
    public final int x;
    public final int y;
    
    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    @Override
    public String toString() {
        return "x=" + x + ",y=" + y;
    }
}

enum Direction {
    NORTH(1, 0),
    SOUTH(-1 ,0),
    WEST(0, 1),
    EAST(0, -1);
    
    public final int a;
    public final int b;
    
    Direction(int a, int b) {
        this.a = a;
        this.b = b;
    }
}


class Element {
    public final Position position;
    public final int dirIndex;
    
    public Element(Position position, int index) {
        this.position = position;
        this.dirIndex = index;
    }
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");;
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[][] map = new int[n][m];
		int[][] paths = new int[n][m]; 
		boolean[][] isVisited = new boolean[n][m]; 
		for (int i = 0; i < n; i++) {
		    st = new StringTokenizer(bf.readLine(), " ");
		    for (int j = 0; j < m; j++) {
		        map[i][j] = Integer.parseInt(st.nextToken());
		    }
		}
		
		paths[n - 1][m - 1] = 1;
		Stack<Element> stk = new Stack<>();
		stk.add(new Element(new Position(0, 0), 0));
		int reachableCount = 0;
		
		while(!stk.isEmpty()) {
		    Element backElement = stk.pop();
		    Position curPos = backElement.position;
		    int curIdx = backElement.dirIndex;

	        paths[curPos.x][curPos.y] += reachableCount;
		    
		    while (true) {
		        if (curIdx >= 4) {
		            reachableCount = paths[curPos.x][curPos.y];
		            break;
		        }
		        
		        Position nextPos = new Position(curPos.x + Direction.values()[curIdx].a, curPos.y + Direction.values()[curIdx].b);
		        if (nextPos.x < 0 || nextPos.x >= n || nextPos.y < 0 || nextPos.y >= m) {
		            curIdx += 1;
		            continue;
		        }
		        
		        if (map[nextPos.x][nextPos.y] >= map[curPos.x][curPos.y]) {
		            curIdx += 1;
		            continue;
		        }
		        
                if (paths[nextPos.x][nextPos.y] > 0) {
                    paths[curPos.x][curPos.y] += paths[nextPos.x][nextPos.y];
                    curIdx += 1;
		            continue;
		        }
		        
		        if (isVisited[nextPos.x][nextPos.y]) {
		            curIdx += 1;
		            continue;
		        }
		        
		        stk.push(new Element(curPos, curIdx + 1));
		        isVisited[curPos.x][curPos.y] = true;
		        curPos = nextPos;
		        curIdx = 0;
		    }
		     
		}
		
		System.out.println(paths[0][0]);
	}
}