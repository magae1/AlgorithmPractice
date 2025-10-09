import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

  private static Queue<Area> q = new LinkedList<>();
  private static int totalSum = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(bf.readLine());
    Area[] areas = new Area[n];

    StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
    for (int i = 0; i < n; i++) {
      int p = Integer.parseInt(st.nextToken());
      totalSum += p;
      areas[i] = new Area(i, p);
    }
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(bf.readLine(), " ");
      int m = Integer.parseInt(st.nextToken());
      while (m > 0) {
        int j = Integer.parseInt(st.nextToken());
        areas[i].addNearestArea(areas[j - 1]);
        m--;
      }
    }
    int minDiff = Integer.MAX_VALUE;
    int maxSize = (int) Math.pow(2, n);
    for (int s = 1; s <= maxSize; s++) {
      int fstSum = bfs(areas[0], s);
      boolean isBitOn = (s & areas[0].bit) > 0;
      int idx = 0;
      while (idx < n) {
        int b = 1 << idx;
        if (isBitOn) {
          if ((s & b) == 0) {
            break;
          }
        } else {
          if ((s & b) > 0) {
            break;
          }
        }
        idx++;
      }
      if (idx >= n) {
        continue;
      }

      int secSum = bfs(areas[idx], s);
      if (fstSum + secSum == totalSum) {
        minDiff = Math.min(minDiff, Math.abs(fstSum - secSum));
      }
    }
    System.out.println((minDiff == Integer.MAX_VALUE ? -1 : minDiff));
  }

  public static int bfs(Area start, int bitmask) {
    q.add(start);
    int visited = start.bit;
    int partSum = start.population;
    boolean isBitOn = (bitmask & start.bit) > 0;
    while (!q.isEmpty()) {
      Area currentArea = q.poll();
      for (Area nextArea : currentArea.getNearestAreaSet()) {
        if ((visited & nextArea.bit) > 0) {
          continue;
        }
        if (isBitOn) {
          if ((bitmask & nextArea.bit) == 0) {
            continue;
          }
        } else {
          if ((bitmask & nextArea.bit) > 0) {
            continue;
          }
        }

        q.add(nextArea);
        visited = visited | nextArea.bit;
        partSum += nextArea.population;
      }
    }

    return partSum;
  }
}

class Area {

  public final int num;
  public final int bit;
  public final int population;
  private final Set<Area> nearestAreaSet = new HashSet<>();

  public Area(int n, int p) {
    this.num = n;
    this.bit = 1 << n;
    this.population = p;
  }

  public void addNearestArea(Area area) {
    this.nearestAreaSet.add(area);
  }

  public Set<Area> getNearestAreaSet() {
    return this.nearestAreaSet;
  }

  @Override
  public String toString() {
    return "N: " + this.num;
  }
}