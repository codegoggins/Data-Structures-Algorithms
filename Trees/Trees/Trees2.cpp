#include<bits/stdc++.h>
using namespace std;

// TAKE INPUT DFS

template<typename T>
class TreeNode{
    public:
    T val;
    vector<TreeNode<T>*>children;

    // Constructor
    TreeNode(T val){
       this->val = val;
    }

    ~TreeNode(){
     for(int i=0;i<children.size();i++){
        delete children[i];
     }
    }
};

// PRINT TREE

void printTree(TreeNode<int>*root){
    cout<<root->val<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->val<<" , ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

// TAKE INPUT 
TreeNode<int>* takeInput(){
    int rootVal;
    cout<<"Enter Value"<<endl;
    cin>>rootVal;

    TreeNode<int>*root = new TreeNode<int>(rootVal);

    int n;
    cout<<"Enter number of children of "<<rootVal<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        TreeNode<int>*child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main(){
   TreeNode<int>*root = takeInput();
   printTree(root);
}