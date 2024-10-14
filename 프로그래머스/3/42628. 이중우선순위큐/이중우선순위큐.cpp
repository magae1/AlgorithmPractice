#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Node {
public:
    int num;
    Node* left_node;
    Node* right_node;
    
    Node(int n) {
        this->num = n;
        left_node = nullptr;
        right_node = nullptr;
    }
};

int get_min(Node* head_node) {
    if (head_node == nullptr) return 0;
    
    Node* cur_node = head_node;
    while(cur_node->left_node) {
        cur_node = cur_node->left_node;
    }
    return cur_node->num;
}

int get_max(Node* head_node) {
    if (head_node == nullptr) return 0;
    
    Node* cur_node = head_node;
    while(cur_node->right_node) {
        cur_node = cur_node->right_node;
    }
    return cur_node->num;
}

void add_node(Node** head_node_ptr, int num) {
    Node* new_node = new Node(num);
    if (*head_node_ptr == nullptr) {
        *head_node_ptr = new_node;
        return;
    }
    
    Node* cur_node = *head_node_ptr;
    while(true) {
        int offset = cur_node->num;
        if (offset < num) {
            if (cur_node->right_node == nullptr) {
                cur_node->right_node = new_node;                
                break;
            } else {
                cur_node = cur_node->right_node;   
            }
        } else {
            if (cur_node->left_node == nullptr) {
                cur_node->left_node = new_node;
                break;
            } else {
                cur_node = cur_node->left_node;   
            }
        }
    }
}

void delete_min_node(Node** head_node_ptr) {
    if (*head_node_ptr == nullptr) return;
    Node* prev_node = nullptr;
    Node* cur_node = *head_node_ptr;
    while(cur_node->left_node) {
        prev_node = cur_node;
        cur_node = cur_node->left_node;
    }
    
    if (prev_node == nullptr) {        
        *head_node_ptr = cur_node->right_node;
    } else {
        prev_node->left_node = cur_node->right_node;   
    }
}

void delete_max_node(Node** head_node_ptr) {
    if (*head_node_ptr == nullptr) return;
    Node* prev_node = nullptr;
    Node* cur_node = *head_node_ptr;
    while(cur_node->right_node) {
        prev_node = cur_node;
        cur_node = cur_node->right_node;
    }
    
    if (prev_node == nullptr) {
        *head_node_ptr = cur_node->left_node;
    } else {
        prev_node->right_node = cur_node->left_node;   
    }
}

vector<int> solution(vector<string> operations) {
    Node* head_node = nullptr;
    for (string operation : operations) {
        stringstream sstream; 
        sstream.str(operation);
        string op;
        int num;
        sstream >> op;
        sstream >> num;
        
        if (op == "I") {
            add_node(&head_node, num);
        } else {
            if (num == -1) {
                delete_min_node(&head_node);                
            } else {
                delete_max_node(&head_node);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = get_max(head_node);
    answer[1] = get_min(head_node);
    return answer;
}