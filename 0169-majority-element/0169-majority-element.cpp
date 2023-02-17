class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        sort(nums.begin(), nums.end());
        for(int i=0,j=1;i<n&&j<n;){
            if(nums[i]==nums[j]){
                count++;
                j++;
            }
            else {
                i=j;
                count=1;
                j++;
            }
            if(count>n/2){
                return nums[i];
            }
        }
        return nums[0];
    }
};