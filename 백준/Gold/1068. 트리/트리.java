import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;

class Node {
    private List<Node> children = new ArrayList<>();
    private boolean removed = false;
    
    public void addChild(Node node) {
        this.children.add(node);
    }
    
    public List<Node> getChildren() {
        return this.children;
    }
    
    public void remove() {
        this.removed = true;
    }
    
    public boolean getRemoved() {
        return this.removed;
    }
    
    public boolean isLeaf() {
        return (!this.removed && children.stream().filter(child -> !child.getRemoved()).count() == 0);
    }
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(bf.readLine());
		int rootIdx = -1;
		
		Node[] nodes = new Node[n];
		for (int i = 0; i < n; i++) {
		    nodes[i] = new Node();
		}
		
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
        for (int i = 0; i < n; i++) {
            int parentIdx = Integer.parseInt(st.nextToken());
            if (parentIdx == -1) {
                rootIdx = i;
            } else {
                nodes[parentIdx].addChild(nodes[i]);
            }
        }
        
        int k = Integer.parseInt(bf.readLine());
        Queue<Node> qu = new LinkedList<>();
        qu.add(nodes[k]);
        nodes[k].remove();
        while(!qu.isEmpty()) {
            Node frontNode = qu.poll();
            for (Node nextNode : frontNode.getChildren()) {
                qu.add(nextNode);
                nextNode.remove();
            }
        }
        
        long num = Arrays.stream(nodes).filter(node -> node.isLeaf()).count();
        System.out.println(num);
	}
}