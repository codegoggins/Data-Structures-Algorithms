// INSERTION SORT
// In insertion sort no swapping of elements is done only shifting of elements is done.

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
   
   for(int i=1;i<n;i++){
      int current = arr[i];
      int j;
      for(j = i-1;j>=0;j--){
         if(current < arr[j]){
            arr[j+1] = arr[j];
         }else{
            break;
         }
      }
      arr[j+1] = current;
   }
}

int main(){
  int arr[] = {7,5,30,8,6,3,2,21,25};
  insertionSort(arr,9);
  for(int i=0;i<9;i++){
    cout<<arr[i]<<" ";
  }
}