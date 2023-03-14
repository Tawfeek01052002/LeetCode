class Solution {
public:
    // steps:
    // 1. counting freq of characters
    // 2. finding max character with count
    // 3. put the characters with +2 diff
    // 4. checking if max_char is not fitting in the length
    
    //T.C.=O(n) S.C.=O(n)
    string reorganizeString(string s) {
//         int heap[26]={0};
//         int n=s.length();
//         for(int i=0;i<n;i++){
//             heap[s[i]-'a']++;
//         }
        
//         int max_char=0;
//         int max_count=INT_MIN;
//         for(int i=0;i<26;i++){
//             if(heap[i]>max_count){
//                 max_count=heap[i];
//                 max_char=i;
//             }
//         }
        
//         int i=0;
//         char ch=max_char+'a';
//         while(max_count>0 && i<n){
//             s[i]=ch;
//             i+=2;
//             max_count--;
//         }
//         heap[max_char]=0;
        
//         if(max_count!=0){
//             return "";
//         }
        
//         for(int j=0;j<26;j++){
//             while(heap[j]>0){
//                 if(i>=n){
//                     i=1;
//                 }
//                 s[i]=j+'a';
//                 i+=2;
//                 heap[j]--;
//             }
//         }
        
//         return s;
        
        
        
        //Using Priority Queue
        
        int n=s.length();
        int heap[26]={0};
        priority_queue<pair<int, char>> que;
        for(int i=0;i<n;i++){
            heap[s[i]-'a']++;
            if(heap[s[i]-'a']>(s.size()+1)/2){
                return "";
            }
        }
        for(int i=0;i<26;i++){
            if(heap[i]){
                que.push({heap[i],(i+'a')});
            }
        }
    
        int i=0;
        pair<int,char> prev=que.top();
        char ch=prev.second;
        que.pop();
        s[i++]=ch;
        
        while(!que.empty()){
            pair<int,char> curr=que.top();
            char ch1=curr.second;
            que.pop();
            s[i++]=ch1;
            if(--prev.first)que.push(prev);
            prev=curr;
        }
        return s;
    }
};