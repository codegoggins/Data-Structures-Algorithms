// SUBSETS (ITERATIVE METHOD)

// PROBLEM LINK:https://leetcode.com/problems/subsets/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>>res = {{}};
    for(auto it:nums){
        int n = res.size();
        for(int i=0;i<n;i++){
           res.push_back(res[i]);
           res.back().push_back(it);
        }
    }
    return res;
}

int main(){
   cout<<"Enter size of array"<<endl;
   vector<int>nums;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      int x;
      cout<<"Enter Element"<<endl;
      cin>>x;
      nums.push_back(x);
   }
   vector<vector<int>> ans = subsets(nums);

   for(int i=0;i<ans.size();i++){
     cout<<"[ ";

    //  The Size of columns depends on each subset size
     for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
     }
     cout<<"]";
     cout<<endl;
   }
}

/*

TIME & SPACE COMPLEXITY


T.C = O(2*2^N)
S.C = O(2*2^N)

N = Size Of Input Vector Array Nums

Why?

The time complexity of the subsets function in the given code is O(2^N * N), where N is the size of the input vector nums.

The outer loop iterates through each element in nums, and the inner loop iterates through the current size of res, which can grow up to 2^N as it generates all possible subsets. Inside the inner loop, the push_back operation is performed, which takes constant time.

So, for each element in nums, the inner loop performs 2^N iterations in total. Hence, the total number of iterations is proportional to 2^N * N, resulting in a time complexity of O(2^N * N).

The space complexity of the function is O(2^N * N) as well. This is because the resultant res vector can contain up to 2^N subsets, and each subset can have up to N elements. Therefore, the total amount of space required to store all subsets is proportional to 2^N * N, resulting in a space complexity of O(2^N * N).

*/

