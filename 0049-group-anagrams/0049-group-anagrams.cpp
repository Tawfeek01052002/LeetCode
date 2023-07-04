class Solution {
public:
    
    std::array<int,256> getHash(string s){
        std::array<int,256> arr={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]]++;
        }
        return arr;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //using map 
        map<std::array<int,256>,vector<string>> mp;
        for(auto ele:strs){
            mp[getHash(ele)].push_back(ele);
        }
        
        vector<vector<string>> ans;
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};