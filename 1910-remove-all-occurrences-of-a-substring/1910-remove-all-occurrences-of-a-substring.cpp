class Solution {
public:
    void removeOcc(string& s,string& t){
        int index=s.find(t);
        if(index==string::npos){
            return;
        }
        else{
            s.erase(index,t.length());
        }
        
        removeOcc(s,t);
    }
    string removeOccurrences(string& s, string& part) {
        // int index=s.find(part);
        // while(index!=string::npos){
        //     s.erase(index,part.length());
        //     index=s.find(part);
        // }
        // return s;
        removeOcc(s,part);
        return s;
    }
};