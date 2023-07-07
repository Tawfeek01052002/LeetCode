class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[1];
        
        //getting minimum and maximum
        for(auto ele:nums){
            mini=min(ele,mini);
            maxi=max(ele,maxi);
        }
        
        // using eclid algorithm to find gcd
        while(maxi && mini){
            if(maxi>mini)
                maxi=maxi-mini;
            else
                mini=mini-maxi;
        }
        
        return maxi?maxi:mini;
    }
};