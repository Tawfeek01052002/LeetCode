class Solution {
public:
    
    //Intution 
    // reverse full array
    //then reverse 1-k
    //then k-n
    void reverse(vector<int>& arr,int start,int end){
        while(start<=end){
            swap(arr[start++],arr[end--]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2)
            return;
        k=k%nums.size();
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};