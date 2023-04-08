#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T val;
    TreeNode<T>*left;
    TreeNode<T>*right;

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

// INPUT BINARY TREE LEVEL WISE

TreeNode<int>* takeInput(){
    cout<<"Enter Root Value"<<endl;
    int rootVal;
    cin>>rootVal;
    if(rootVal == -1){
        return nullptr;
    }
    TreeNode<int>*root = new TreeNode<int>(rootVal);
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>*node = q.front();
        q.pop();
        cout<<"Enter Left Child Of "<<node->val<<" : ";
        int leftVal;
        cin>>leftVal;
        if(leftVal != -1){
        TreeNode<int>*leftChild = new TreeNode<int>(leftVal);
        q.push(leftChild);
        node->left = leftChild;
        }

        cout<<"Enter Right Child Of "<<node->val<<" : ";
        int rightVal;
        cin>>rightVal;
        if(rightVal != -1){
        TreeNode<int>*rightChild = new TreeNode<int>(rightVal);
        q.push(rightChild);
        node->right = rightChild;
        }
    }
    return root;
}

// PRINT BINARY TREE

void printTree(TreeNode<int>*root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" : ";
    if(root->left){
    cout<<root->left->val<<" , ";
    }
    if(root->right){
    cout<<root->right->val;
    }
    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

int main(){
   TreeNode<int>*root = takeInput();
   printTree(root);
   delete(root);
}