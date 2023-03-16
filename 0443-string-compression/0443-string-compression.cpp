class Solution {
public:
    
    //Run Length encoding 
    //T.C.=O(N)  S.C.=O(1)
    int compress(vector<char>& chars) {
        int n=chars.size();
        char curr=chars[0];
        int k=0,count=1;
        
        for(int j=1;j<n;j++){
            if(curr!=chars[j]){
                chars[k++]=curr;
                if(count>1){
                    int start=k;
                    while(count){
                        chars[k++]=(count%10)+'0';
                        count/=10;
                    }
                    reverse(chars.begin()+start,chars.begin()+k);
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
            int start=k;
            while(count){
                chars[k++]=(count%10)+'0';
                count/=10;
            }
            reverse(chars.begin()+start,chars.begin()+k);
        }
        
        return k;
    }
};