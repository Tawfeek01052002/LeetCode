class Solution {
public:
    int firstUniqChar(string s) {
        //worst case
        //T.C.=O(n) S.C.=O(1)
        // int n=s.length();
        // if(n==1)
        //     return 0;
        // for(int i=0;i<n;i++){
        //     bool flag=false;
        //     for(int j=0;j<n;j++){
        //         if(i!=j && s[i]==s[j]){
        //             flag=true;
        //             break;
        //         }
        //     }
        //     if(!flag){
        //         return i;
        //     }
        // }
        // return -1;
        
        //Good Solution
        //T.C.=O(n) S.C.=O(1)
        int arr[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(arr[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};