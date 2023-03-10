class Solution {
public:
    bool isPalindrome(string str, int s, int e)
{
    while (s < e)
    {
        if (str[s] != str[e])
            return false;
        s++;
        e--;
    }
    return true;
}
int countSubstrings(string str1)
{
    int n = str1.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(str1, i, j))
            {
                count++;
            }
            // cout << str1.substr(i, j) << endl;
        }
    }
    return count;
}
};