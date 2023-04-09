#include<bits/stdc++.h>
using namespace std;

void generate(int index,unordered_map<int,int>&curr,vector<int>&nums,int k,int &count){

    if(index == nums.size()){
        count++;
        return;
    }   

    //not include
    generate(index+1,curr,nums,k,count);

    // include
    if(!curr[nums[index]+k] && !curr[nums[index]-k]){
        curr[nums[index]]++;
        generate(index+1,curr,nums,k,count);
        curr[nums[index]]--;
    }
}

int beautifulSubsets(vector<int>& nums, int k) {
    unordered_map<int,int>curr;
    int count = 0;
    generate(0,curr,nums,k,count);
    return count-1;
}

int main(){
   vector<int>nums;
   int n;
   cout<<"Enter array size :"<<endl;
   cin>>n;
   cout<<"Enter array elements :"<<endl;
   for(int i=0;i<n;i++){
     int x;
     cin>>x;
     nums.push_back(x);
   }
   int k;
   cout<<"Enter difference k :"<<endl;
   cin>>k;
   cout<<beautifulSubsets(nums,k);
}

/*

TIME & SPACE COMPLEXITY


T.C = O(2^N)
S.C = O(N)

The time complexity of the beautifulSubsets function in the given code is O(2^N), where N is the size of the input nums vector. This is because the function uses a recursive approach to generate all possible subsets of nums, and at each level of the recursion, there are two choices: either include the current element or not include it. As a result, the total number of recursive calls grows exponentially with the size of nums, leading to a time complexity of O(2^N).

The space complexity of the beautifulSubsets function is O(N), where N is the size of the input nums vector. This is because the function uses an unordered map curr to keep track of the current subset being generated, and the maximum size of curr would be equal to the size of nums in the worst case. Additionally, the function uses a constant amount of space for the count variable and the function call stack during recursion, which does not depend on the size of nums. Therefore, the overall space complexity is O(N).
*/
