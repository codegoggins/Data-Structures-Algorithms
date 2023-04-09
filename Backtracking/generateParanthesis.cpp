#include<bits/stdc++.h>
using namespace std;

void generate(int open,int close,string &s,vector<string>&ans){
    
    if(open == 0 && close == 0){
        ans.push_back(s);
        return;
    }

    if(open > 0){
        s.push_back('(');
        generate(open-1,close,s,ans);
        s.pop_back();
    }

    if(close > 0 && open < close){
        s.push_back(')');
        generate(open,close-1,s,ans);
        s.pop_back();
    } 
}

vector<string> generateParenthesis(int n) {
    vector<string>ans;
    string s;
    generate(n,n,s,ans);
    return ans;
}

int main(){
   int n;
   cin>>n;
   vector<string>ans = generateParenthesis(n);
   for(int i=0;i<ans.size();i++){
      cout<<" '"<<ans[i]<<"' ";
      cout<<endl;
    }

}