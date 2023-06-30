class Solution {
public:
    string removeOccurrences(string s, string part) {
        int index;
        while(true){
            index=s.find(part);
            if(index==string::npos){
                return s;
            }
            s.erase(index,part.length());
        }
        return s;
    }
};