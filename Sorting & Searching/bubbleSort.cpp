// BUBBLE SORT 
// After One Traversal The Largest Element is at its correct position

// Which is better bubble , selection or insertion

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
   
   for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }    
        }
   }
}

int main(){
  int arr[] = {7,5,30,8,6,3,2,21,25};
  bubbleSort(arr,9);
  for(int i=0;i<9;i++){
    cout<<arr[i]<<" ";
  }
}