#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
 private:
  char alpha;
  bool is_ended;
  Node* child[26] = {
      nullptr,
  };

 public:
  Node(char alpha, bool is_ended) {
    this->alpha = alpha;
    this->is_ended = is_ended;
  }
  Node* next(char alpha) { return this->child[alpha - 'a']; }
  Node* insert_or_move(char alpha, bool is_ended) {
    if (this->child[alpha - 'a'] != nullptr) {
      if (is_ended) {
        this->child[alpha - 'a']->set_is_ended(true);
      }
      return this->child[alpha - 'a'];
    }
    return this->child[alpha - 'a'] = new Node(alpha, is_ended);
  }
  bool get_is_ended() { return this->is_ended; }
  void set_is_ended(bool is_ended) { this->is_ended = is_ended; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Node* root = new Node(0, false);
  int n, m;
  cin >> n >> m;

  while (n--) {
    string input;
    cin >> input;

    Node* cur_node = root;
    int size = input.size() - 1;
    for (int i = 0; i < size; i++) {
      cur_node = cur_node->insert_or_move(input[i], false);
    }
    cur_node = cur_node->insert_or_move(input[size], true);
  }

  int count = 0;
  while (m--) {
    string input;
    cin >> input;

    bool is_matched = true;
    Node* cur_node = root;
    int size = input.size() - 1;
    for (int i = 0; i < size; i++) {
      Node* next_node = cur_node->next(input[i]);
      if (next_node == nullptr) {
        is_matched = false;
        break;
      }
      cur_node = next_node;
    }
    cur_node = cur_node->next(input[size]);
    if (cur_node == nullptr || !cur_node->get_is_ended()) {
      is_matched = false;
    }

    if (is_matched) {
      count++;
    }
  }

  cout << count << '\n';
  return 0;
}