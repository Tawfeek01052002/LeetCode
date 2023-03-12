
class Solution {
public:
    //Solving Using custom comparator by checking which string is greter by adding s1+s2 & s2+s1
    static bool cmp(int first,int second){
        string s1=to_string(first);
        string s2=to_string(second);
        return (s1+s2)>(s2+s1)?true:false;
    }
    
    //T.C. = O(nlogn)   S.C. = O(1)
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        for(int i=0;i<nums.size();i++)
            ans+=to_string(nums[i]);
        //edge test case i.e if the ans number is starting with 0 hence the largest number is also 0
        if(nums[0]==0)
            return "0";
        return ans;
    }
};