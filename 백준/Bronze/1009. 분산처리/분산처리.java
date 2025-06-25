import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(bf.readLine());
        while (t > 0) {
            StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            a = a % 10;
            int i = a % 10;
            while (b > 1) {
                i = i * a;
                i = i % 10;
                b--;
            }

            System.out.println(i == 0 ? 10 : i);
            t--;
        }
    }
}