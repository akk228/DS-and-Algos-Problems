/*
 You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

 struct Node {
   int val;
   Node *left;
   Node *right;
   Node *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

 Initially, all next pointers are set to NULL.
 */
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

void Perfect_Binary_Tree (Node* & tree, int hight, int First_value){
    if ( hight == 0 ) return;
    
    tree = new Node(First_value);
    
    Perfect_Binary_Tree(tree->left, hight - 1, First_value + 1);
    Perfect_Binary_Tree(tree->right, hight - 1, First_value*10);
    
};

Node* connect (Node* root){
    if ( root == nullptr ) return root;
    
    Node* aux_node_left  = root->left;
    Node* aux_node_right = root->right;
 
    while ( aux_node_left != nullptr ) {
        aux_node_left->next = aux_node_right;
        aux_node_left = aux_node_left->right;
        aux_node_right = aux_node_right->left;
    };
    
    connect(root->left);
    connect(root->right);
    return root;
};

int main() {
    Node* root,*newroot;
    Perfect_Binary_Tree(root, 3, 1);
    newroot = connect(root);
    cout << newroot->val << endl;
    cout << newroot->right->left->next->val;
    cout << endl;
    return 0;
}
