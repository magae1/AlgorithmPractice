import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    Question[] questions = new Question[n];
    for (int i = 0; i < n; i++) {
      questions[i] = new Question(i + 1);
    }

    while (m > 0) {
      st = new StringTokenizer(bf.readLine(), " ");
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      questions[b - 1].addFrontQuestion(questions[a - 1]);
      questions[a - 1].addBackQuestion(questions[b - 1]);
      m--;
    }

    PriorityQueue<Question> qu = new PriorityQueue<>();
    for (Question question : questions) {
      if (question.isFrontQuestionEmpty()) {
        qu.add(question);
      }
    }

    List<Question> order = new LinkedList<>();
    while (!qu.isEmpty()) {
      Question currentQuestion = qu.poll();
      order.add(currentQuestion);

      for (Question backQuestion : currentQuestion.getBackQuestions()) {
        backQuestion.removeFrontQuestion(currentQuestion);
        if (backQuestion.isFrontQuestionEmpty()) {
          qu.add(backQuestion);
        }
      }
    }

    for (Question question : order) {
      System.out.print(question.id + " ");
    }
    System.out.println();
  }
}

class Question implements Comparable<Question> {

  public final int id;
  private final Set<Question> frontQuestionSet = new HashSet<>();
  private final PriorityQueue<Question> backQuestionQueue = new PriorityQueue<>();

  public Question(int id) {
    this.id = id;
  }

  public void addFrontQuestion(Question question) {
    this.frontQuestionSet.add(question);
  }

  public void addBackQuestion(Question question) {
    this.backQuestionQueue.add(question);
  }

  public boolean isFrontQuestionEmpty() {
    return frontQuestionSet.isEmpty();
  }

  public Collection<Question> getBackQuestions() {
    return this.backQuestionQueue;
  }

  public void removeFrontQuestion(Question question) {
    this.frontQuestionSet.remove(question);
  }


  @Override
  public boolean equals(Object obj) {
    if (!(obj instanceof Question)) {
      return false;
    }
    return this.id == ((Question) obj).id;
  }

  @Override
  public int compareTo(Question o) {
    return this.id - o.id;
  }
}