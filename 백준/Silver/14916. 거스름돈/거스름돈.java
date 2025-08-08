import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static final int FIVE = 5;
    static final int TWO = 2;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int numOfFives = n / FIVE;
		while (numOfFives >= 0) {
		    int remain = n - (numOfFives * FIVE);
		    if (remain % TWO == 0) {
		        System.out.println(numOfFives + (remain / TWO));
		        return;
		    }
		    numOfFives--;
		}
		
		System.out.println(-1);
	}
}