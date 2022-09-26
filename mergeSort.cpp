#include<bits/stdc++.h>

using namespace std;
void merge(int *arr,int start,int end){
   int mid =(start + (end-start)/2);
   int len1 = mid-start+1;
   int len2 = end-mid;
   int *first = new int[len1];
   int *second = new int[len2];
   
   int arrayIndex = start;

// copying the first array
int k=start;
 for(int i = 0;i<len1;i++){
    first[i] = arr[k++];
 }

 // copying the second array
k = mid+1;
 for(int i = 0;i<len2;i++){
    second[i] = arr[k++];
 }
 int index1 = 0;
 int index2 = 0;
 arrayIndex = start;
 while(index1<len1 && index2<len2){
    if(first[index1]<second[index2]){
        arr[arrayIndex++] = first[index1++];
    }
    else{
        arr[arrayIndex++] = second[index2++];
    }
 }

 while(index1<len1){
   arr[arrayIndex++] = first[index1++];
 }
 while(index2<len2){
    arr[arrayIndex++] = second[index2++];
 }

    delete []first;
    delete []second;
 
}
void mergeSort(int *arr,int start,int end){
 if(start>=end){
    return;
  }

  int mid = (start+(end-start)/2);
  // merge sort recursion logic
  mergeSort(arr,start,mid);
  mergeSort(arr,mid+1,end);
  merge(arr,start,end);

}

int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
      cin>>arr[i];
    }
    
    mergeSort(arr,0,n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 
