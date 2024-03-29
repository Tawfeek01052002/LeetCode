class Solution {
public:
      
    // using two pointer approach
    // main test case when count>10  ---> store in reverse then reverse it
    // good solution
    //Compression algorithm-- run length encoding
    // T.C.=O(n) S.C.=O(1)
    int compress(vector<char>& chars) {
        char prev=chars[0];
        int count=1;
        int index=0;
        for(int i=1;i<chars.size();i++){
            if(prev==chars[i])
                count++;
            else{
                chars[index++]=prev;
                if(count>1){
                    int start=index;
                    while(count!=0){
                        chars[index++]=(count%10)+'0';
                        count/=10;
                    }
                    int end=index;
                    reverse(chars.begin()+start,chars.begin()+end);
                }
                prev=chars[i];
                count=1;
            }
        }
        chars[index++]=prev;
        if(count>1){
            int start=index;
                    while(count!=0){
                        chars[index++]=(count%10)+'0';
                        count/=10;
                    }
                    int end=index;
                    reverse(chars.begin()+start,chars.begin()+end);
        }
        return index;
    }
};