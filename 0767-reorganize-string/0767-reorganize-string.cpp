class Solution {
public:
    string reorganizeString(string s) {
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