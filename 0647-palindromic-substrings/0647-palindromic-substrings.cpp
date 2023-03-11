class Solution {
public:
    int isPalindrome(string str,int i,int j){
        int count=0;
        int n=str.length();
        while(i>=0 && j<n){
            if(str[i]==str[j]){
                count++;
                i--;
                j++;
            }
            else{
                return count;
            }
        }
        return count;
    }
    int countSubstrings(string str1)
    {
        int n = str1.length();
        int count = 0;
        for (int i = 0,j=i; i < n && j<n; i++,j++)
        {
            count+=isPalindrome(str1,i,j);
            count+=isPalindrome(str1,i,j+1);
        }
        return count;
    }
    
};