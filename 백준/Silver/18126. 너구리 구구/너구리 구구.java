import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;


class Path {
    public final int roomNum;
    public final long distance;
    
    public Path(int num, long distance) {
        this.roomNum = num;
        this.distance = distance;
    }
}

class Room {
    private final List<Path> pathList = new ArrayList<>();
    private boolean isVisited = false;
    
    public void addPath(Path path) {
        this.pathList.add(path);
    }
    
    public boolean getIsVisited() {
        return this.isVisited;
    }
    
    public void setIsVisited(boolean isVisited) {
        this.isVisited = isVisited;
    }
    
    public List<Path> getPathList() {
        return this.pathList;
    }
}


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(bf.readLine());
		
		Room[] rooms = new Room[n + 1];
		for (int i = 1; i <= n; i++) {
		    rooms[i] = new Room();
		}
		
		StringTokenizer st;
		for (int i = 1; i < n; i++) {
		    st = new StringTokenizer(bf.readLine(), " ");    
		    int a = Integer.parseInt(st.nextToken());
		    int b = Integer.parseInt(st.nextToken());
		    long c = Long.parseLong(st.nextToken());
		    
		    rooms[a].addPath(new Path(b, c));
		    rooms[b].addPath(new Path(a, c));
		}
		
		long logestDistance = 0;
		Queue<Path> qu = new LinkedList<>();
		qu.add(new Path(1, 0));
		rooms[1].setIsVisited(true);
		
		while(!qu.isEmpty()) {
		    Path curPath = qu.poll();
		    Room curRoom = rooms[curPath.roomNum];
		    for (Path p : curRoom.getPathList()) {
		        Room nextRoom = rooms[p.roomNum];
		        
		        if (nextRoom.getIsVisited()) continue;
		        
		        long distance = curPath.distance + p.distance;
		        logestDistance = Math.max(logestDistance, distance);
		        nextRoom.setIsVisited(true);
		        qu.add(new Path(p.roomNum, distance));
		    }
		}
		
		System.out.println(logestDistance);
	}
}