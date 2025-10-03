import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(bf.readLine());
    Building[] buildings = new Building[n];
    for (int i = 0; i < n; i++) {
      buildings[i] = new Building(i + 1);
    }

    for (int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(bf.readLine(), " ");

      int t = Integer.parseInt(st.nextToken());
      buildings[i].setTime(t);
      while (st.hasMoreTokens()) {
        int b = Integer.parseInt(st.nextToken());
        if (b == -1) {
          break;
        }
        buildings[i].addPrerequiredBuilding(buildings[b - 1]);
        buildings[b - 1].addAfterBuilding(buildings[i]);
      }
    }

    Queue<Building> qu = new LinkedList<>();
    for (Building building : buildings) {
      if (building.isFrontQuestionEmpty()) {
        qu.add(building);
      }
    }

    while (!qu.isEmpty()) {
      Building currentBuilding = qu.poll();

      for (Building afterBuilding : currentBuilding.getAfterBuildings()) {
        afterBuilding.removePrerequiredBuilding(currentBuilding);
        if (afterBuilding.isFrontQuestionEmpty()) {
          qu.add(afterBuilding);
        }
        afterBuilding.setPrevTime(currentBuilding.getTotalTime());
      }

    }

    for (Building building : buildings) {
      System.out.println(building.getTotalTime());
    }
  }
}

class Building {

  public final int id;
  private int time = 0;
  private int prevTime = 0;
  private final Set<Building> frontBuildingSet = new HashSet<>();
  private final List<Building> afterBuildingList = new ArrayList<>();

  public Building(int id) {
    this.id = id;
  }

  public void addPrerequiredBuilding(Building building) {
    this.frontBuildingSet.add(building);
  }

  public void addAfterBuilding(Building building) {
    this.afterBuildingList.add(building);
  }

  public boolean isFrontQuestionEmpty() {
    return frontBuildingSet.isEmpty();
  }

  public Collection<Building> getAfterBuildings() {
    return this.afterBuildingList;
  }

  public void removePrerequiredBuilding(Building building) {
    this.frontBuildingSet.remove(building);
  }

  public void setPrevTime(int prevTime) {
    this.prevTime = Math.max(this.prevTime, prevTime);
  }

  public int getTotalTime() {
    return this.prevTime + time;
  }

  public void setTime(int time) {
    this.time = time;
  }

  @Override
  public boolean equals(Object obj) {
    if (!(obj instanceof Building)) {
      return false;
    }
    return this.id == ((Building) obj).id;
  }
}