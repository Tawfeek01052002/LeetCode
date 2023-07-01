class Solution {
public:
    static bool cmp(int a,int b){
        if(to_string(a)+to_string(b)>to_string(b)+to_string(a)){
            return true;
        }
        return false ;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
        if(nums[0]==0)
            return "0";
        return ans;
    }
};