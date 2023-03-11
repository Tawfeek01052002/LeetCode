class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[256]={0};
        int sn=s.length();
        int tn=t.length();
        for(int i=0;i<sn;i++){
            // cout<<(int)s[i]<<endl;
            arr[(int)s[i]]+=1;
            // cout<<arr[(int)s[i]]<<endl;
        }
        for(int i=0;i<tn;i++){
            arr[(int)t[i]]--;
        }
        for(int i=0;i<256;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
        
    }
};