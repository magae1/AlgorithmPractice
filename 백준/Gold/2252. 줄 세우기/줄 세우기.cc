#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Student {
 private:
  set<short> front_students;
  set<short> back_students;

 public:
  void add_front_student_idx(short student_idx) {
    this->front_students.insert(student_idx);
  }
  void add_back_student_idx(short student_idx) {
    this->back_students.insert(student_idx);
  }
  set<short>& get_back_students() { return this->back_students; }
  bool is_empty_front_students() { return this->front_students.size() == 0; }
  void remove_front_student(short student_idx) {
    this->front_students.erase(student_idx);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<Student> students = vector<Student>(n + 1);

  while (m--) {
    short a, b;
    cin >> a >> b;
    students[b].add_front_student_idx(a);
    students[a].add_back_student_idx(b);
  }

  vector<short> line;
  queue<short> qu;
  for (int i = 1; i <= n; i++) {
    if (students[i].is_empty_front_students()) {
      qu.push((short)i);
    }
  }

  while (!qu.empty()) {
    short front_idx = qu.front();
    line.push_back(front_idx);
    qu.pop();

    set<short> back_students = students[front_idx].get_back_students();
    for (short back_idx : back_students) {
      students[back_idx].remove_front_student(front_idx);
      if (students[back_idx].is_empty_front_students()) {
        qu.push(back_idx);
      }
    }
  }

  for (short l : line) {
    cout << l << ' ';
  }
  cout << '\n';
  return 0;
}