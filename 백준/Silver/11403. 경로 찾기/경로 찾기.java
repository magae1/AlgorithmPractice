import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(bf.readLine());
    boolean[][] path = new boolean[n][n];
    for (int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
      for (int j = 0; j < n; j++) {
        int p = Integer.parseInt(st.nextToken());
        path[i][j] = p == 1;
      }
    }

    for (int m = 0; m < n; m++) {
      for (int s = 0; s < n; s++) {
        for (int e = 0; e < n; e++) {
          if (path[s][m] && path[m][e]) {
            path[s][e] = true;
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print((path[i][j] ? 1 : 0) + " ");
      }
      System.out.println();
    }
  }
}
