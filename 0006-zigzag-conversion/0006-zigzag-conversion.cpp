class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int n=s.length();
        int k=0;
        vector<string> zigzag(numRows);
        while(k<n){
            for(int i=0;i<numRows && k<n;i++){
                zigzag[i].push_back(s[k++]);
            }

            for(int i=numRows-2;i>0 && k<n;i--){
                zigzag[i].push_back(s[k++]);
            }
        }
        string ans;
        for(string str:zigzag){
            ans+=str;
        }
        return ans;
    }
};