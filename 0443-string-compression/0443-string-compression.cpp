class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        char curr=chars[0];
        int j,k,count=1;
        for(j=1,k=0;j<n;j++){
            if(curr!=chars[j]){
                chars[k++]=curr;
                if(count>1){
                    string temp=to_string(count);
                    for(char ch:temp){
                        chars[k++]=ch;   
                    }
                }
                count=1;
                curr=chars[j];
            }
            else{
                count++;
            }
        }
        chars[k++]=curr;
        if(count>1){
            string temp=to_string(count);
            for(char ch:temp){
                chars[k++]=ch;   
            }
        }
        while(k<chars.size())
            chars.pop_back();
        
        return chars.size();
    }
};