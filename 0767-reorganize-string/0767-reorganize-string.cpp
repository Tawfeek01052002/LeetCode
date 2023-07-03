class Solution {
public:
    
    //storing maximum count based on that checking if max>n+1/2  then not possible 
    //else store character on differnce of i+2
    string reorganizeString(string s) {
        int n=s.length();
        int arr[26]={0};
        char maxOcc=s[0];
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']>arr[maxOcc-'a'])
                maxOcc=s[i];
        }
        if(arr[maxOcc-'a']>(n+1)/2)
            return "";
        
        string ans(n,' ');
        
        int i=0;
        while(arr[maxOcc-'a']!=0){
                ans[i]=maxOcc;
                arr[maxOcc-'a']--;
                i+=2;
        }
        for(int j=0;j<26;j++){
            while(arr[j]!=0){
                if(i>=n)
                    i=1;
                ans[i]=j+'a';
                arr[j]--;
                i+=2;
            }
        }
        return ans;
    }
};