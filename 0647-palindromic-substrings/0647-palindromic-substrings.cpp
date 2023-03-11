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
    
    //we are check that substring(i,j) is palindrome or not if yes
    // then i-- and j++ again check with this
    // two cases comes of even length substring and odd length substring
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
        for (int i = 0; i < n ; i++)
        {
            count+=isPalindrome(str1,i,i);
            count+=isPalindrome(str1,i,i+1);
        }
        return count;
    }
    
};