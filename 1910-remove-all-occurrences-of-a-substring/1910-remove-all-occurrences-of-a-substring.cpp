class Solution {
public:
    // Using find function to search substring if found 
    // then remove substring using erase function
    // of string 
    string removeOccurrences(string s, string part) {
        int pos=s.find(part);
        while(pos!= string::npos){
            s.erase(pos,part.length());
            pos=s.find(part);
        }
        return s;
    }
};