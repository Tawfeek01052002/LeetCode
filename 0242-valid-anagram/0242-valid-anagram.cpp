class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[128]={0};
        for(int i=0;i<s.length();i++)
            arr[s[i]]++;
        for(int i=0;i<t.length();i++)
            arr[t[i]]--;
        for(int i=97;i<128;i++){
            if(arr[i]!=0)
                return false;
        }
        return true;
    }
};