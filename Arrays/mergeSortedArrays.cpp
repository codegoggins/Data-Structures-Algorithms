// MERGE TWO SORTED ARRAYS

#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int n,int arr2[],int m,int ans[]){
    
    int i=0,j=0,k=0;

    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
             ans[k] = arr1[i];
             i++;
             k++;
        }else{
            ans[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < n){
        ans[k] = arr1[i];
        i++;
        k++;
    }

    while(j < m){
        ans[k] = arr2[j];
        j++;
        k++;
    }
}

int main(){
   int n = 5 , m = 8; 
   int arr1[] = {3,8,9,21,32};
   int arr2[] = {5,12,15,30,50,100,105,1000};
   int ans[m+n];
   merge(arr1,n,arr2,m,ans);

   for(int i=0;i<m+n;i++){
    cout<<ans[i]<<" ";
   }

}