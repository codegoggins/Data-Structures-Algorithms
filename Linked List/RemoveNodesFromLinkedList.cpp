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
WE WILL GET TLE FOR THIS PROGRAM FOR LARGE TEST CASES BECAUSE -->

The time complexity of our solution is O(N^2) because for each node, we are checking all nodes to its right side. 
This approach is inefficient and can result in TLE when the input size is large.

*/
ListNode* removeNodes(ListNode* head) {
        if(head->next == nullptr){
            return head;
        }
        ListNode*curr,*prev,*nextNode;

        // DUMMY NODE
        ListNode*d = new ListNode();
        d->next = head;
        prev = d,curr=head,nextNode=curr->next;

        while(nextNode != nullptr){
            if(curr-> val < nextNode->val){
                prev->next=nextNode;
                prev = d;
                curr = prev->next;
                nextNode = curr->next;
            }else{
                prev = curr;
                curr = nextNode;
                nextNode = curr->next;
            }
        }
        return d->next;

}