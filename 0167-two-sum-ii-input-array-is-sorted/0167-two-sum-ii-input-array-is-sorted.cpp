class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        //Two Pointer Approach
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
    }
};