
class Solution {
public:
    bool operator()(int first,int second){
        string s1=to_string(first);
        string s2=to_string(second);
        return (s1+s2)>(s2+s1)?true:false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),Solution());
        string ans="";
        for(int i=0;i<nums.size();i++)
            ans+=to_string(nums[i]);
        if(nums[0]==0)
            return "0";
        return ans;
    }
};