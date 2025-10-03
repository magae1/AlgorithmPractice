import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    Student[] students = new Student[n];
    for (int i = 0; i < n; i++) {
      students[i] = new Student(i + 1);
    }

    while (m > 0) {
      st = new StringTokenizer(bf.readLine(), " ");
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      students[b - 1].addFrontStudent(students[a - 1]);
      students[a - 1].addBackStudent(students[b - 1]);
      m--;
    }

    Queue<Student> qu = new LinkedList<>();
    for (Student student : students) {
      if (student.getFrontStudentSet().isEmpty()) {
        qu.add(student);
      }
    }

    List<Student> line = new LinkedList<>();
    while (!qu.isEmpty()) {
      Student currentStudent = qu.poll();
      line.add(currentStudent);

      for (Student backStudent : currentStudent.getBackStudentSet()) {
        backStudent.getFrontStudentSet().remove(currentStudent);
        if (backStudent.getFrontStudentSet().isEmpty()) {
          qu.add(backStudent);
        }
      }
    }

    for (Student student : line) {
      System.out.print(student.id + " ");
    }
    System.out.println();
  }
}

class Student {

  public final int id;
  private final Set<Student> frontStudentSet = new HashSet<>();
  private final Set<Student> backStudentSet = new HashSet<>();

  public Student(int id) {
    this.id = id;
  }

  public void addFrontStudent(Student student) {
    frontStudentSet.add(student);
  }

  public void addBackStudent(Student student) {
    backStudentSet.add(student);
  }

  public Set<Student> getFrontStudentSet() {
    return frontStudentSet;
  }

  public Set<Student> getBackStudentSet() {
    return backStudentSet;
  }

  @Override
  public boolean equals(Object obj) {
    if (!(obj instanceof Student)) {
      return false;
    }
    return this.id == ((Student) obj).id;
  }
}