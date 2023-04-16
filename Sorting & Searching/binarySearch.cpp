// BINARY SEARCH

//  In Binary Search , the Input Array needs to be sorted

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int x){
    int start = 0 , end =n-1;
    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] > x){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
  int arr[] = {5,6,7,8,9,10,15,20,25};
  cout<<binarySearch(arr,9,20)<<endl;
}