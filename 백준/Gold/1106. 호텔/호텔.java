import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
		List<int[]> list = new ArrayList<>();
		
		int c = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int answer = Integer.MAX_VALUE;
		int[] buf = new int [c + 1];
		Arrays.fill(buf, Integer.MAX_VALUE);
		
		for (int i = 0; i < n; i++) {
		    st = new StringTokenizer(bf.readLine(), " ");
		    int cost = Integer.parseInt(st.nextToken());
		    int customer = Integer.parseInt(st.nextToken());
		    
		    if (customer > c) {
		        answer = Math.min(answer, cost);
		    } else {
		        list.add(new int[]{customer, cost});    
		        if (buf[customer] > cost) {
		            buf[customer] = cost;
		        }
		    }
		}
		
		for (int t = 1; t <= c; t++) {
		    for (int r = 1; r <= t; r++) {
		        if (buf[r] != Integer.MAX_VALUE && buf[t - r] != Integer.MAX_VALUE) {
		            buf[t] = Math.min(buf[r] + buf[t - r], buf[t]);
		        }
		    }
		}
		
        answer = Math.min(answer, buf[c]);
		for (int[] arr : list) {
		    int customer = arr[0];
		    int cost = arr[1];
		    
		    for (int bufIdx = c - customer + 1; bufIdx <= c; bufIdx++) {
		        if (buf[bufIdx] != Integer.MAX_VALUE) {
		            answer = Math.min(answer, buf[bufIdx] + cost);    
		        }
		    }
		}
		
		System.out.println(answer);
	}
}