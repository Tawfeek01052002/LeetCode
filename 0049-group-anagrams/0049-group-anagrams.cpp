class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        map<string,vector<string>> mp;
        
        for(auto ele:strs){
            string s=ele;
            sort(s.begin(),s.end());
            mp[s].push_back(ele);
        }
        
        vector<vector<string>> ans;
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};