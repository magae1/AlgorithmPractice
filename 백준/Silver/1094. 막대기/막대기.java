import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    short x = Short.parseShort(bf.readLine());
    short ans = 0;
    for (short i = 1; i <= 64; ) {
      if ((x & i) > 0) {
        ans++;
      }
      i = (short) (i << 1);
    }
    System.out.println(ans);
  }
}
