// NEXT GREATER ELEMENT I

// BRUTE FORCE

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
    vector<int>ans;
    bool flag;
    for(int i=0;i<nums1.size();i++){

        for(int j=0;j<nums2.size();j++){
                
                if(nums1[i] == nums2[j]){
                
                flag = true;

                    if(j == nums2.size()-1){
                        ans.push_back(-1);
                        break;
                    }else{

                        for(int k=j+1;k<nums2.size();k++){
                            if(nums2[k] > nums2[j]){
                            ans.push_back(nums2[k]);
                            flag = false;
                            break;
                            }
                        }

                        if(flag == true){
                            ans.push_back(-1);
                        }
                    }
                    
                }
            
        }
    }
    return ans;
}


// USING STACK DATA STRUCTURE

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int>v;
    stack<int>st;

    for(int i=nums2.size()-1;i>=0;i--){
        if(st.size() == 0){
            v.push_back(-1);
        }
        else if(st.top() > nums2[i]){
            v.push_back(st.top());
        }else if(st.top() <= nums2[i]){
            while(st.size()>0 && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.size() == 0){
                v.push_back(-1);
            }else{
                v.push_back(st.top());
            }
        }
        st.push(nums2[i]);
    }
    reverse(v.begin(),v.end());
    unordered_map<int,int>mp;
    for(int i=0;i<nums2.size();i++){
        mp[nums2[i]] = v[i];
    }
    
    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}


int main(){
   
}