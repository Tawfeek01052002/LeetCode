class Solution {
public:
    string reorganizeString(string s) {
        int heap[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            heap[s[i]-'a']++;
        }
        
        int max_char=0;
        int max_count=INT_MIN;
        for(int i=0;i<26;i++){
            if(heap[i]>max_count){
                max_count=heap[i];
                max_char=i;//Storing chararacter index
            }
        }
        
        int i=0;
        char ch=max_char+'a';
        while(max_count>0 && i<n){
            s[i]=ch;
            i+=2;
            max_count--;
        }
        heap[max_char]=0;
        
        if(max_count!=0){
            return "";
        }
        
        for(int j=0;j<26;j++){
            while(heap[j]>0){
                if(i>=n){
                    i=1;
                }
                s[i]=j+'a';
                i+=2;
                heap[j]--;
            }
        }
        
        return s;
        
    }
};