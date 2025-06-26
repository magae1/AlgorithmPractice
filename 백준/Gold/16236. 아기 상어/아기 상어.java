import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


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

class Position implements Comparable<Position> {
    public final int i;
    public final int j;
    
    Position(int i, int j) {
        this.i = i;
        this.j = j;
    }
    
    @Override
    public int compareTo(Position p) {
        int gap = this.i - p.i;
            if (gap == 0) {
                return this.j - p.j;
            }
        return gap;
    }
    
    @Override
    public String toString() {
        return "i: " + i + ", j: " + j;
    }
}

class Shark {
    private Position position;
    private int size = 2;
    private int count = 0;
    
    Shark (int i, int j) {
        this.position = new Position(i, j);
    }
    
    public void eat() {
        count += 1;
        if (size == count) {
            count = 0;
            size += 1;
        }
    }
    
    public int getSize() {
        return this.size;
    }
    
    public void setPosition(Position position) {
        this.position = position;
    }
    
    public Position getPosition() {
        return this.position;
    }
    @Override
    public String toString() {
        return "Shark position: " + position + ", count: " + count + ", size: " + size;
    }
}

class Path implements Comparable<Path> {
    public final Position position;
    public final int time;
    
    Path(int i, int j, int time) {
        this.position = new Position(i, j);
        this.time = time;
    }
    
    Path(Position position, int time) {
        this.position = position;
        this.time = time;
    }
    
    @Override
    public int compareTo(Path p) {
        int interval = this.time - p.time;
        if (interval == 0) {
            return this.position.compareTo(p.position);
        }
        return interval;
    }
    
    @Override
    public String toString() {
        return "position: " + this.position + ", time: " + this.time;
    }
}

public class Main {
    
    private static final int POSITION_SHARK = 9;

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		Shark shark = null;
		
        
        int t = 0;
        int n = Integer.parseInt(bf.readLine());
        int[][] space = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine(), " ");
            
            for (int j = 0; j < n; j++) {
                space[i][j] = Integer.parseInt(st.nextToken());
                
                if (space[i][j] == POSITION_SHARK) {
                    shark = new Shark(i, j);
                    space[i][j] = 0;
                }
            }
        }
        
        while(true) {
            Path pt = findShortestPath(shark, space, n);
            if (pt == null) {
                break;
            }
            shark.setPosition(pt.position);
            shark.eat();
            space[pt.position.i][pt.position.j] = 0;
            t += pt.time;
        }
        
        System.out.println(t);
	}
	
	private static Path findShortestPath(Shark shark, int[][] space, int n) {
	    boolean[][] isVisited = new boolean[n][n];
	    int minTime = Integer.MAX_VALUE;
	    
	    PriorityQueue<Path> pq = new PriorityQueue<>();
	    Queue<Path> qu = new LinkedList<>();
	    Position sharkPosition = shark.getPosition();
	    isVisited[sharkPosition.i][sharkPosition.j] = true;
	    qu.add(new Path(sharkPosition, 0));
	    while(!qu.isEmpty()) {
	        Path curPath = qu.poll();
	        
	        if (minTime <= curPath.time) {
	            break;
	        }
	        
	        for (Direction dir : Direction.values()) {
	            Position nextPos = new Position(curPath.position.i + dir.i, curPath.position.j + dir.j);
	            
	            if (nextPos.i < 0 || nextPos.i >= n || nextPos.j < 0 || nextPos.j >= n) {
	                continue;
	            }
	            if (isVisited[nextPos.i][nextPos.j]) {
	                continue;
	            }
	            
	            int fishSize = space[nextPos.i][nextPos.j];
	            int nextTime = curPath.time + 1;
	            if (fishSize == 0 || shark.getSize() == fishSize) {
	                isVisited[nextPos.i][nextPos.j] = true;
	                qu.add(new Path(nextPos, nextTime));
	            } else if (shark.getSize() > fishSize) {
	                isVisited[nextPos.i][nextPos.j] = true;
	                pq.add(new Path(nextPos, nextTime));
	                minTime = nextTime;
	            }
	        }
	       
	    }
	    return pq.poll();
	}
	
}