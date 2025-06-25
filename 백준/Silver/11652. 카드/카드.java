import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.HashMap;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Map<Long, Integer> map = new HashMap<>();
		map.put(0L, 0);
        
        long targetNum = 0;
		int n = Integer.parseInt(bf.readLine());
		while (n > 0) {
		    long input = Long.parseLong(bf.readLine());
		    if (map.containsKey(input)) {
		        map.replace(input, map.get(input) + 1);
		    } else {
		        map.put(input, 1);
		    }
		    
		    int cmp = map.get(input).compareTo(map.get(targetNum));
		    if (cmp > 0) {
		        targetNum = input;    
		    } else if (cmp == 0 && input < targetNum) {
		        targetNum = input;
		    }
		    n--;
		}
		
		System.out.println(targetNum);
	}
}