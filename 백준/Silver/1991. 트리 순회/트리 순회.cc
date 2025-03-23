#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
 private:
  char alpha;
  Node* left_node = nullptr;
  Node* right_node = nullptr;

 public:
  Node(char alpha) { this->alpha = alpha; }
  void insert_left(Node* node) { this->left_node = node; }
  void insert_right(Node* node) { this->right_node = node; }
  char get_alpha() { return this->alpha; }
  Node* get_left_node() { return this->left_node; }
  Node* get_right_node() { return this->right_node; }
};

void print_perorder(Node* root) {
  stack<Node*> stk;
  Node* cur_node = root;
  while (cur_node != nullptr) {
    cout << cur_node->get_alpha();

    if (cur_node->get_left_node()) {
      stk.push(cur_node);
      cur_node = cur_node->get_left_node();
      continue;
    }

    Node* right_node = cur_node->get_right_node();
    if (right_node) {
      cur_node = right_node;
      continue;
    }

    while (!stk.empty()) {
      Node* top_node = stk.top();
      stk.pop();
      right_node = top_node->get_right_node();
      if (right_node != nullptr) break;
    }
    cur_node = right_node;
  }
  cout << '\n';
}

void print_inorder(Node* root) {
  Node* cur_node = root;
  stack<Node*> stk;
  while (cur_node != nullptr) {
    if (cur_node->get_left_node()) {
      stk.push(cur_node);
      cur_node = cur_node->get_left_node();
      continue;
    }

    cout << cur_node->get_alpha();

    Node* right_node = cur_node->get_right_node();
    if (right_node) {
      cur_node = right_node;
      continue;
    }

    while (!stk.empty()) {
      Node* top_node = stk.top();
      cout << top_node->get_alpha();
      stk.pop();
      right_node = top_node->get_right_node();
      if (right_node != nullptr) break;
    }
    cur_node = right_node;
  }
  cout << '\n';
}

void print_postorder(Node* root) {
  Node* cur_node = root;
  stack<pair<Node*, bool>> stk;
  while (true) {
    while (cur_node != nullptr) {
      stk.push({cur_node, false});
      cur_node = cur_node->get_left_node();
    }

    while (!stk.empty()) {
      pair<Node*, bool> top = stk.top();
      stk.pop();
      cur_node = top.first;
      if (top.second || cur_node->get_right_node() == nullptr) {
        cout << cur_node->get_alpha();
        continue;
      }
      stk.push({cur_node, true});
      cur_node = cur_node->get_right_node();
      break;
    }
    if (stk.empty()) break;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Node* nodes[26];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    nodes[i] = new Node((char)(i + 'A'));
  }

  while (n--) {
    char a, b, c;
    cin >> a >> b >> c;

    if (b - 'A' >= 0) {
      nodes[a - 'A']->insert_left(nodes[b - 'A']);
    }
    if (c - 'A' >= 0) {
      nodes[a - 'A']->insert_right(nodes[c - 'A']);
    }
  }

  print_perorder(nodes[0]);
  print_inorder(nodes[0]);
  print_postorder(nodes[0]);

  return 0;
}