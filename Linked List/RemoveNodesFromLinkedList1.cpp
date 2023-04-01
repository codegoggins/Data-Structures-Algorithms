#include<bits/stdc++.h>
using namespace std;

  class ListNode {
    public:
      int val;
      ListNode*next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
   };


/* 
WE CAN ALSO SOLVE THIS USING STACK -->
You can optimize the solution by using a stack data structure. The idea is to keep track of the nodes that have a value greater than the current node. If we encounter a node with a greater value, we remove all the nodes from the stack until we find a node with a smaller or equal value. 
After processing all nodes, the stack will contain only the nodes that should be kept in the modified linked list.
*/

