class Solution {
public:
    
    //we are using vectors to store character 
    //like we are traversing throw vector  
    //like placing charcter if numRows=3 then on 0, 1, 2, 
    //then 1, 0  then 1, 2 likewise 
    
    
    string convert(string s, int numRows) {
        if(numRows==1 ||s.length()==1){
            return s;
        }
        vector<string> ans(numRows);
        int row=0;
        int index=0;
        while(index<s.length()){
            while(index<s.length() && row<numRows){
                ans[row++].push_back(s[index++]);
            }
            
            row=numRows-2;
            while(index<s.length() && row>=0){
               ans[row--].push_back(s[index++]);
            }
            row=1;
        }
        string out="";
        for(string str:ans){
            out+=str;
        }
        return out;
    }
};