class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> maps;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(maps.find(temp) == maps.end()){
                vector<string> inner;
                inner.push_back(strs[i]);
                maps[temp]=inner;
            }
            else{
                maps[temp].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> ans;
        for(auto key:maps){
            ans.push_back(key.second);
        }
        return ans;
    }
};