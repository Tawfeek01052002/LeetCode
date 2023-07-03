class Solution {
public:
     // steps:
    // 1. counting freq of characters
    // 2. finding max character with count
    // 3. put the characters with +2 diff
    // 4. checking if max_char is not fitting in the length
    
    //storing maximum count based on that checking if max>n+1/2  then not possible 
    //else store character on differnce of i+2
    
    string reorganizeString(string s) {
        
        //T.C.=O(n) S.C.=O(1)
        int n=s.length();
        int arr[26]={0};
        char maxOcc=s[0];
        
        //adding frequency of character on array with size 26
        // and during this we are finding maxOccured character
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']>arr[maxOcc-'a'])
                maxOcc=s[i];
        }
        
        //checking not possible condition
        if(arr[maxOcc-'a']>(n+1)/2)
            return "";
        
        string ans(n,' ');
        
        //filling the output string on difference of i+2
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
        
        //Using Priority Queue
        //T.C.=? S.C.=?
//         int n=s.length();
//         int heap[26]={0};
//         priority_queue<pair<int, char>> que;
//         for(int i=0;i<n;i++){
//             heap[s[i]-'a']++;
//             if(heap[s[i]-'a']>(s.size()+1)/2){
//                 return "";
//             }
//         }
//         for(int i=0;i<26;i++){
//             if(heap[i]){
//                 que.push({heap[i],(i+'a')});
//             }
//         }
    
//         int i=0;
//         pair<int,char> prev=que.top();
//         char ch=prev.second;
//         que.pop();
//         s[i++]=ch;
        
//         while(!que.empty()){
//             pair<int,char> curr=que.top();
//             char ch1=curr.second;
//             que.pop();
//             s[i++]=ch1;
//             if(--prev.first)que.push(prev);
//             prev=curr;
//         }
//         return s;
    }
};