import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(bf.readLine(), " ");

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    List<Edge> edgeList = new ArrayList<>(m);
    while (m > 0) {
      st = new StringTokenizer(bf.readLine(), " ");
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      int t = Integer.parseInt(st.nextToken());

      edgeList.add(new Edge(a, b, t));
      m--;
    }

    long[] distances = new long[n + 1];
    Arrays.fill(distances, Long.MAX_VALUE);
    distances[1] = 0;

    for (int i = 1; i < n; i++) {
      for (Edge e : edgeList) {
        if (distances[e.from] != Long.MAX_VALUE) {
          distances[e.to] = Math.min(distances[e.to], distances[e.from] + e.time);
        }
      }
    }

    for (Edge e : edgeList) {
      if (distances[e.from] != Long.MAX_VALUE
          && distances[e.from] + e.time < distances[e.to]) {
        System.out.println(-1);
        return;
      }
    }

    for (int i = 2; i <= n; i++) {
      long d = distances[i];
      System.out.println(d == Long.MAX_VALUE ? -1 : d);
    }
  }
}

class Edge {

  public final int from;
  public final int to;
  public final int time;

  public Edge(int from, int to, int time) {
    this.time = time;
    this.from = from;
    this.to = to;
  }

}