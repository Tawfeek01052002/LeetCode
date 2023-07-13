class Solution {
public:
    void removeOcc(string& s,string& t){
        int index=s.find(t);
        if(index==string::npos){
            return;
        }
        else{
            // s.erase(index,t.length());
            //this erase function can also be done as
            string left=s.substr(0,index);
            string right=s.substr(index+t.size(),s.size());
            s=left+right;
            removeOcc(s,t);
        }
        
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