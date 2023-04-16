// SELECTION SORT

// AFTER 1 traversal the smallest element is at its correct position 

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
   
   for(int i=0;i<n-1;i++){
      
      int minEl = arr[i],minIndex=i;

      for(int j=i+1;j<n;j++){
         if(arr[j] < minEl){
            minEl = arr[j];
            minIndex = j;
         }
      }
    // SWAP ELEMENTS
    int temp = arr[i];
    arr[i] = minEl;
    arr[minIndex] = temp;
   }
}

int main(){
  int arr[] = {7,5,30,8,6,3,2,21,25};
  selectionSort(arr,9);
  for(int i=0;i<9;i++){
    cout<<arr[i]<<" ";
  }
}