class Solution {
public:
    //T.C.=O
    void merge(vector<int>& nums,int s,int m,int e){
        int len1=m-s+1;
        int len2=e-m;
        
        int * left=new int[len1];
        int * right=new int[len1];
        
        int k=s;
        for(int i=0;i<len1;i++){
            left[i]=nums[k++];
        }
        k=m+1;
        for(int i=0;i<len2;i++){
            right[i]=nums[k++];
        }
        
        int i=0;
        int j=0;
        k=s;
        while(i<len1 && j<len2){
            if(left[i]<right[j]){
                nums[k++]=left[i++];
            }
            else{
                nums[k++]=right[j++];
            }
        }
        while(i<len1){
            nums[k++]=left[i++];
        }
        
        while(j<len2){
            nums[k++]=right[j++];
        }
        
    }
    void mergeSort(vector<int>& nums,int s,int e){
        if(s>=e){
            return;
        }
        int mid=s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        mergeSort(nums,s,e);
        return nums;
    }
};