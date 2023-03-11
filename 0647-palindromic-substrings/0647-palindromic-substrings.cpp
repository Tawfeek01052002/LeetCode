class Solution {
public:
    // bool isPalindrome(string str, int s, int e)
    // {
    //     while (s < e)
    //     {
    //         if (str[s] != str[e])
    //             return false;
    //         s++;
    //         e--;
    //     }
    //     return true;
    // }
    
    // Brute force approach checking all possible substring is palindrome       or not 
    // int countSubstrings(string str1)
    // {
    //     int n = str1.length();
    //     int count = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i; j < n; j++)
    //         {
    //             if (isPalindrome(str1, i, j))
    //             {
    //                 count++;
    //             }
    //             // cout << str1.substr(i, j) << endl;
    //         }
    //     }
    //     return count;
    // }
    
    
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
    
    //Optimised Approach
    int countSubstrings(string str1)
    {
        int n = str1.length();
        int count = 0;
        for (int i = 0,j=i; i < n && j<n; i++,j++)
        {
            count = count + isPalindrome(str1,i,j)+isPalindrome(str1,i,j+1);
        }
        return count;
    }
    
};