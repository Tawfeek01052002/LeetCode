class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr, count=0, n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(count==0){
                curr=nums[i];
                count++;
            }
            else if(nums[i]!=curr)
                count--;
            else
                count++;
        }
        return curr;
    }
};