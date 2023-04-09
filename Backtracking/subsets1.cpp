// SUBSETS (RECURSIVE METHOD)

// PROBLEM LINK:https://leetcode.com/problems/subsets/description/

#include<bits/stdc++.h>
using namespace std;

void subsetsHelper(int index,vector<int>&curr,vector<vector<int>>&ans,vector<int>&nums){
   
if(index == nums.size()){
    ans.push_back(curr);
    return;
}

//Exclude the element at this index
subsetsHelper(index+1,curr,ans,nums);

//Include the element at this index
curr.push_back(nums[index]);
subsetsHelper(index+1,curr,ans,nums);
curr.pop_back();
} 

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>>ans;
    vector<int>curr={};
    subsetsHelper(0,curr,ans,nums);
    return ans;

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


*/

