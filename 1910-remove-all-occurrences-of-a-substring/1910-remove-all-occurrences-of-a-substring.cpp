class Solution {
public:
    
    //Using find function to search the starting index of the
    // part string and removing it with erase function
    string removeOccurrences(string s, string part) {
        int n=part.length();
        int index=s.find(part);
        while(index!=string::npos){
            s.erase(index,n);
            index=s.find(part);
        }
        return s;
    }
};