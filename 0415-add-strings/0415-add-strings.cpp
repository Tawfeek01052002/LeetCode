class Solution {
public:
    // string getSumString(string num1,int n1,string num2,int n2,string ans,int carry){
    //     if()
    // }
    string addStrings(string num1, string num2) {
        
        int n1=num1.length();
        int n2=num2.length();
        string ans;
        int carry=0;
        while(n1>0 && n2>0){
            int digit=num1[n1-1]-'0'+num2[n2-1]-'0'+carry;
            ans.push_back((digit%10)+'0');
            carry=digit/10;
            n1--;
            n2--;
        }
        while(n1>0){
            int digit=num1[n1-1]-'0'+carry;
            ans.push_back((digit%10)+'0');
            carry=digit/10;  
            n1--;
        }
        while(n2>0){
            int digit=num2[n2-1]-'0'+carry;
            ans.push_back((digit%10)+'0');
            carry=digit/10;
            n2--;
        }
        if(carry>0){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};