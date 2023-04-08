// TAKE INPUT LEVELWISE

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
   public:
   T val;
   vector<TreeNode<T>*>children;

   //constructor
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

// TAKE INPUT DFS (LEVELWISE)

TreeNode<int>* takeInput(){
    int rootVal;
    cout<<"Enter root value"<<endl;
    cin>>rootVal;
    TreeNode<int>*root = new TreeNode<int>(rootVal);

    queue<TreeNode<int>*>q;
    q.push(root);

    while(q.size() != 0){
       TreeNode<int>*node = q.front();
       q.pop();

       cout<<"Enter Number of Children of "<<node->val<<endl;
       int num;
       cin>>num;

       for(int i=0;i<num;i++){
          cout<<"Enter "<<i<<"th child value"<<endl;
          int childData;
          cin>>childData;

          TreeNode<int>*child = new TreeNode<int>(childData);
          node->children.push_back(child);
          q.push(child);
       }
    }
    return root;
}

int main(){
   TreeNode<int>*root = takeInput();
   printTree(root);
   delete root;
}