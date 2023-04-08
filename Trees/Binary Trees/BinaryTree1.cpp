// BINARY TREE

#include<bits/stdc++.h>
using namespace std;

// BINARY TREE CLASS

template<typename T>
class TreeNode{
    public:
    T val;
    TreeNode*left;
    TreeNode*right;

    // Constructor
    TreeNode(T val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode(){
        delete left;
        delete right;
    }
};

// PRINT BINARY TREE

void printTree(TreeNode<int>*root){
    if(root == nullptr)return;

    cout<<root->val<<" : ";

    if(root->left)cout<<"L : "<<root->left->val<<" , ";
    if(root->right)cout<<"R : "<<root->right->val;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int main(){
   TreeNode<int>*root = new TreeNode<int>(1);
   TreeNode<int>*node1 = new TreeNode<int>(2);
   TreeNode<int>*node2 = new TreeNode<int>(3);
   root->left = node1;
   root->right = node2;
   printTree(root);
}