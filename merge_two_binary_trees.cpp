/*
 You are given two binary trees root1 and root2.

 Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

 Return the merged tree.
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    TreeNode* newTree = nullptr;
    if (root1 != nullptr and root2 != nullptr) {
        newTree = new TreeNode( root1->val + root2->val );
        
        newTree->left  = mergeTrees( root1->left , root2->left  );
        newTree->right = mergeTrees( root1->right, root2->right );
    }
    if (root1 != nullptr and root2 == nullptr) {
        newTree = new TreeNode( root1->val );
        
        newTree->left  = mergeTrees( root1->left , root2 );
        newTree->right = mergeTrees( root1->right, root2 );
    }
    if (root1 == nullptr and root2 != nullptr) {
        newTree = new TreeNode( root2->val );
        
        newTree->left  = mergeTrees( root1 , root2->left  );
        newTree->right = mergeTrees( root1, root2->right );
    }
    if (root1 == nullptr and root2 == nullptr) {
        newTree = nullptr;
    }
    return newTree;
}

void postorder_traverse (TreeNode* tree, vector<int> & trav){
    if (tree == nullptr) return;
    
    postorder_traverse(tree->left,trav);
    
    postorder_traverse(tree->right,trav);
    
    trav.push_back(tree->val);
    //cout << tree->data << "->";
};

int main() {
    TreeNode* tree1 = nullptr, *tree2 = nullptr, *merged_tree;
    vector<int> PO_trav;
    
    tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree2 = new TreeNode(4);
    tree2->left = new TreeNode(5);
    tree2->left->left = new TreeNode(6);
    merged_tree = mergeTrees(tree1, tree2);
    postorder_traverse(merged_tree, PO_trav);
    for (const auto o : PO_trav){
        cout << o << "->";
    }
    return 0;
}
