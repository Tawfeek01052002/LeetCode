class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0;i<n&&j<n;j++){
            if(nums[j]!=0){
                nums[i]=nums[j];
                if(i!=j){
                    nums[j]=0;
                }
                i++;
            }
        }
    }
};