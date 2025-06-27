import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

class Node {
    public final int num;
    public final int count;
    
    Node(int num, int count) {
        this.num = num;
        this.count = count;
    }
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
		
		int s = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
		Queue<Node> qu = new LinkedList<>();
		qu.add(new Node(e, 1));
		while(!qu.isEmpty()) {
		    Node f = qu.poll();
		    if (f.num < 1) continue; 
		    
		    if (f.num % 2 == 0) {
		        int nextNum = f.num / 2;
		        if (nextNum == s) {
		            System.out.println(f.count + 1);
		            return;
		        }
		        qu.add(new Node(nextNum, f.count + 1));
		    }
		    
		    if (f.num % 10 == 1) {
		        int nextNum = f.num / 10;
		        if (nextNum == s) {
		            System.out.println(f.count + 1);
		            return;
		        }
		        qu.add(new Node(nextNum, f.count + 1));
		    }
		}
		
		System.out.println(-1);
	}
}