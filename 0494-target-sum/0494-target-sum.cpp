class Solution {
public:
    int findTargetSumWays(vector<int>& arr,int target,int i){
        if(i>=arr.size() && target==0){
            return 1;
        }
        if(i>=arr.size() && target!=0){
            return 0;
        }
        int count=0;
        count+=findTargetSumWays(arr,target-arr[i],i+1)+ findTargetSumWays(arr,target+arr[i],i+1);
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWays(nums,target,0);
    }
};