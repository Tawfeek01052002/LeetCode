class Solution {
public:
    void getCombo(string& digits, vector<string>& ans,string& str,int i,vector<string>& arr){
        if(i>=digits.length()){
            ans.push_back(str);
            return;
        }
        
        for(int j=0;j<arr[digits[i]-'0'].length();j++){
            str.push_back(arr[digits[i]-'0'][j]);
            getCombo(digits,ans,str,i+1,arr);
            str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
       
        if(digits.length()<=0)
            return {};
        vector<string> ans;
        string str;
        vector<string> arr={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int i=0;
        getCombo(digits,ans,str,i,arr);
        return ans;
        
    }
};