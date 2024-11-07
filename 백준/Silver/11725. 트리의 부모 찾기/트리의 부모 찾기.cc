#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node {
 private:
  int num;
  int parent_node_num;
  vector<Node*> adjust_nodes;

 public:
  Node(int num) {
    this->num = num;
    this->parent_node_num = -1;
  }
  vector<Node*> get_adjust_nodes() { return this->adjust_nodes; }
  void add_adjust_node(Node* node) { this->adjust_nodes.push_back(node); }
  void set_parent_node_num(int num) { this->parent_node_num = num; }
  int get_parent_node_num() { return this->parent_node_num; }
  int get_num() { return this->num; }
};

void dfs(Node* cur_node, int prev_num) {
  if (cur_node->get_parent_node_num() >= 0) {
    return;
  }
  cur_node->set_parent_node_num(prev_num);
  for (Node* child_node : cur_node->get_adjust_nodes()) {
    dfs(child_node, cur_node->get_num());
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<Node*> node_list(n + 1);
  for (int i = 0; i <= n; i++) {
    node_list[i] = new Node(i);
  }

  for (int i = 0; i < n - 1; i++) {
    int l, r;
    cin >> l >> r;
    node_list[l]->add_adjust_node(node_list[r]);
    node_list[r]->add_adjust_node(node_list[l]);
  }

  dfs(node_list[1], 0);

  for (int i = 2; i <= n; i++) {
    cout << node_list[i]->get_parent_node_num() << "\n";
  }

  return 0;
}