//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int len1=m-l+1;
        int len2=r-m;
        
        vector<int> left(len1);
        vector<int> right(len2);
        
        int k=l;
        for(int i=0;i<len1;i++){
            left[i]=arr[k++];
        }
        
        k=m+1;
        for(int i=0;i<len2;i++){
            right[i]=arr[k++];
        }
        
        int i=0;
        int j=0;
        int startIndex=l;
        while(i<len1 && j<len2){
            if(left[i]<right[j]){
                arr[startIndex++]=left[i++];
            }
            else{
                arr[startIndex++]=right[j++];
            }
        }
        while(i<len1){
            arr[startIndex++]=left[i++];
        }
        while(j<len2){
            arr[startIndex++]=right[j++];
        }
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)
            return;
        
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends