class Solution {
public:
    void getSumString(string& num1,int n1,string& num2,int n2,int carry,string& ans){
        
        //base case
        if(n1<0 && n2<0){
            if(carry>0){
                ans.push_back(carry+'0');
                return;
            }
            return ;
        }
            
        //ek case
        int p1=(n1>=0?num1[n1]:'0')-'0';
        int p2=(n2>=0?num2[n2]:'0')-'0';
        int sum=p1+p2+carry;
        int digit=sum%10;
        carry=sum/10;
        getSumString(num1,n1-1,num2,n2-1,carry,ans);
        ans.push_back(digit+'0');
        
    }
    string addStrings(string num1, string num2) {
        
        //T.C.=O(N) S.C.=O(n)
        // int n1=num1.length();
        // int n2=num2.length();
        // string ans;
        // int carry=0;
        // while(n1>0 && n2>0){
        //     int digit=num1[n1-1]-'0'+num2[n2-1]-'0'+carry;
        //     ans.push_back((digit%10)+'0');
        //     carry=digit/10;
        //     n1--;
        //     n2--;
        // }
        // while(n1>0){
        //     int digit=num1[n1-1]-'0'+carry;
        //     ans.push_back((digit%10)+'0');
        //     carry=digit/10;  
        //     n1--;
        // }
        // while(n2>0){
        //     int digit=num2[n2-1]-'0'+carry;
        //     ans.push_back((digit%10)+'0');
        //     carry=digit/10;
        //     n2--;
        // }
        // if(carry>0){
        //     ans.push_back(carry+'0');
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        
        //using recursion
        int n1=num1.length()-1;
        int n2=num2.length()-1;
        string ans="";
        getSumString(num1,n1,num2,n2,0,ans);
        return ans;
    }
};