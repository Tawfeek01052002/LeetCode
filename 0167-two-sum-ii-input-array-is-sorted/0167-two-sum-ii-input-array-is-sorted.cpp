class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        //Two Pointer Approach---O(n)
        for(int i=0,j=arr.size()-1;i<j;){
            if(arr[i]+arr[j]==target){
                return {i+1,j+1};
            }
            else if(arr[i]+arr[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {0};
        
        
        //Binary Search Approach ---O(nlogn)
        for(int i=0;i<arr.size();i++){
            int targ=target-arr[i];
            int index=binarySearch(arr,0,arr.size()-1,targ);
            if(index!=i && index!=-1){
                return {i,index};
            }
        }
        
        
    }
    
    int binarySearch(vector<int> arr,int start,int end,int target){
        while(start<end){
            int mid=(start+end)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
};