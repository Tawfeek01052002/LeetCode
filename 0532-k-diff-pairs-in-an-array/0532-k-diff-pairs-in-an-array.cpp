class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        //Brute force approach
        //T.C.=O(n^2) S.C.=O(n)
        int n=nums.size();
        int count=0;
        set<pair<int,int>> s;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])==k && s.count({nums[i],nums[j]})==0 && s.count({nums[j],nums[i]})==0){
                    s.insert({nums[i],nums[j]});
                    count++;
                }
                    
            }   
        }
        return count;
    }
};