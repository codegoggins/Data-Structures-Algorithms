#include<bits/stdc++.h>
using namespace std;

// TREENODE CLASS

template<typename T>
class TreeNode{
   public:
   T val;
   vector<TreeNode<T>*>children;

   //Constructor
   TreeNode(T val){
      this->val = val;
   }    
};

// FUNCTION TO PRINT GENERIC TREE

void printTree(TreeNode<int>*root){

   if(root == nullptr)return;

   cout<<root->val<<" : ";

   root->children.size();

   for(int i=0;i<root->children.size();i++){
     cout<<root->children[i]->val<<" , ";
   }
   
   cout<<endl;
   for(int i=0;i<root->children.size();i++){
      printTree(root->children[i]);
   }
}

int main(){
   TreeNode<int>*root = new TreeNode<int>(1);
   TreeNode<int>*node1 = new TreeNode<int>(2);
   TreeNode<int>*node2 = new TreeNode<int>(3);

   root->children.push_back(node1);
   root->children.push_back(node2);

   printTree(root);
}