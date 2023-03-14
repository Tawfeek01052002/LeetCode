class Solution {
public:
    
    // we are using the map with pair of string and vector
    // when we sort two string and check that they are anagaram or not 
    // by using == but we are not checking
    // if the two strings are not same then they form a new group
    // we use map to store pair of sorted string with their vector of 
    // string
    
    // T.C=O(n*mlogm)   S.C.=O(n*m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string,vector<string>> maps;
//         int n=strs.size();
//         for(int i=0;i<n;i++){
//             string temp=strs[i];
//             sort(temp.begin(),temp.end());
//             maps[temp].push_back(strs[i]);
          
//         }
        
//         vector<vector<string>> ans;
//         for(auto key:maps){
//             ans.push_back(key.second);
//         }
//         return ans;
        
        
        // T.C=O(n*klogk)  where n=length of vector k=length of maxi string
        // S.C.=O(n)
//         vector<vector<string>> ans;
//         vector<pair<string,string>> sorted;
//         for(string s:strs){
//             string temp=s;
//             sort(temp.begin(),temp.end());
//             sorted.push_back({temp,s});
//         }
        
//         int n=sorted.size();
//         vector<string> temp;
//         sort(sorted.begin(),sorted.end());
//         // for(int i=0;i<n;i++){
//         //     cout<<i+1<<" = "<<sorted[i].second<<" ";
//         // }
//         for(int i=0;i<n;i++){
//             if(i==0){
//                 temp.push_back(sorted[i].second);
//             }
//             else if(sorted[i].first==sorted[i-1].first){
//                 temp.push_back(sorted[i].second);
//             }
//             else{
//                 ans.push_back(temp);
//                 temp.clear();
//                 temp.push_back(sorted[i].second);
//             }
//             // cout<<" count = "<<i<<endl;
            
//         }
//         if(temp.size()>0){
//            ans.push_back(temp); 
//         }
//         return ans;
        
        
        
        // Optimised Solution Using array of 256 size to check that anagram or not
        // T.C=O(n*k)   S.C.=O(n*k)
        map<std::array<int,256>,vector<string>> ans;
        for(auto str:strs){
            std::array<int,256> arr={0};
            for(int j=0;j<str.length();j++){
                arr[str[j]-'a']++;
            }    
            ans[arr].push_back(str);
        }
        
        vector<vector<string>> vec;
        for(auto key:ans){
            vec.push_back(key.second);
        }
        return vec;
        
        
    }
};