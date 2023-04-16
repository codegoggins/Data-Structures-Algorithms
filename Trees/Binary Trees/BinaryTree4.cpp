// BASIC BINARY TREE FUNCIONS

// COUNT NUMBER OF NODES IN BINARY TREE
// FIND NODE IN BINARY TREE
// PREORDER POSTORDER INORDER TRAVERSAL
// HEIGHT OF BINARY
// MIRROR IMAGE BINARY TREE

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

/* <-------------------------------------------------- INPUT & PRINT FUNCTIONS --------------------------------------------->*/

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

// PRINT BINARY TREE LEVELWISE

void printTree(TreeNode<int>*root){
    if(root == nullptr){
        return;
    }
    queue<TreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        TreeNode<int>*node = q.front();
        q.pop();

        if(node == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<node->val<<" : ";
            cout<<"L :";
        }

        if(node->left){
            q.push(node->left);
            cout<<node->left->val<<" , ";
        }else{
            cout<<-1<<" , ";
        }
        cout<<" R: ";

        if(node->right){
            q.push(node->right);
            cout<<node->right->val<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}

/* <-------------------------------------------------- INPUT & PRINT FUNCTIONS --------------------------------------------->*/

// FUNCTIONS


// PREORDER TRAVERSAL
void preorder(TreeNode<int>*root){
    if(root ==nullptr){
        return;
    }
    cout<<root->val<<endl;
    preorder(root->left);
    preorder(root->right);
}


// POSTORDER TRAVERSAL
void postorder(TreeNode<int>*root){
    if(root ==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<endl;
}

// INORDER TRAVERSAL
void inorder(TreeNode<int>*root){
    if(root ==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}

// COUNT NODES
int countNodes(TreeNode<int>*root){
    if(root == nullptr){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//ELEMENT PRESENT IN BINARY TREE OR NOT
bool isPresent(TreeNode<int>*root,int x){
    if(root == nullptr)return false;

    if(root -> val == x)return true;
    
    // If element is present either on left or right true value is returned
    return isPresent(root->left,x) || isPresent(root->right,x);
}

// HEIGHT OF BINARY TREE
int height(TreeNode<int>*root){
    if(root == nullptr){
        return 0;
    }
    // 1 is height of the root added
    // The max of left and right height will be the actual height of the tree 
    return 1 + max(height(root->left),height(root->right));
}

//MIRROR IMAGE OF BINARY TREE
void mirror(TreeNode<int>*root){
    if(root == nullptr)return;

    mirror(root->left);
    mirror(root->right);

    TreeNode<int>*temp = root->right;
    root->right = root->left;
    root->left = temp;
}


int main(){
   TreeNode<int>*root = takeInput();
   printTree(root);
   cout<<endl;
   cout<<"Total Nodes : "<<countNodes(root)<<endl;
   cout<<endl;
   cout<<"PreOrder Traversal : "<<endl;
   preorder(root);
   cout<<endl;
   cout<<"PostOrder Traversal : "<<endl;
   postorder(root);
   cout<<endl;
   cout<<"Inorder Traversal : "<<endl;
   inorder(root);
   cout<<endl;
   isPresent(root,5) ? cout<<"Present" : cout<<"Not Present";
   cout<<endl;
   cout<<"Height : "<<height(root);
   cout<<endl;
   mirror(root);
   printTree(root);
   delete(root);
}