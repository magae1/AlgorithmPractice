import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		Map<String, String> pwMap = new HashMap<>();
		
		for (int i = 0; i < n; i++) {
		    st = new StringTokenizer(br.readLine(), " ");
		    String site = st.nextToken();
		    String password = st.nextToken();
		    pwMap.put(site, password);
		}
		
		for (int i = 0; i < m; i++) {
		    String target = br.readLine();
		    bw.write(pwMap.get(target) + "\n");
		}
		bw.flush();
	}
}