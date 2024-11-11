#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Person {
 private:
  int num;
  int depth;
  vector<Person*> friends;

 public:
  Person(int num) {
    this->num = num;
    this->depth = -1;
  }

  void add_friend(Person* persion) { this->friends.push_back(persion); }
  vector<Person*>& get_friends() { return this->friends; }
  void set_depth(int depth) { this->depth = depth; }
  int get_depth() { return this->depth; }
};

int main() {
  int n, m;
  cin >> n;
  vector<Person*> people(n + 1);
  for (int i = 1; i <= n; i++) {
    people[i] = new Person(i);
  }

  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    people[l]->add_friend(people[r]);
    people[r]->add_friend(people[l]);
  }

  int count = -1;
  queue<Person*> qu;
  people[1]->set_depth(0);
  qu.push(people[1]);
  while (!qu.empty()) {
    Person* cur_person = qu.front();
    int cur_depth = cur_person->get_depth();
    qu.pop();

    if (cur_depth > 2) {
      break;
    }
    count += 1;

    for (Person* next_person : cur_person->get_friends()) {
      if (next_person->get_depth() >= 0) {
        continue;
      }
      next_person->set_depth(cur_depth + 1);
      qu.push(next_person);
    }
  }

  cout << count << endl;
  return 0;
}