class Solution {
public:
    bool isSubsequence(string s, string t) {
        int fir=0,sec=0;
        int ns=s.length();
        int nt=t.length();
        while(fir<ns && sec<nt){
            if(t[sec]==s[fir]){
                fir++;
                sec++;
            }
            else
                sec++;
        }
        if(fir==ns)
            return true;
        return false;
    }
};