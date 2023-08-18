class Solution {
public:
    bool isValid(string s) {
        int index=s.find("abc");
        while(index!=string::npos){
            s.erase(index,3);
            index=s.find("abc");
        }
        return s.size()==0?true:false;
    }
};