//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void getAllPermutation(string  str,int i,vector<string>& ans){
        if(i<0){
            ans.push_back(str);
            return;
        }
        
        for(int j=i;j>=0;j--){
            swap(str[i],str[j]);
            getAllPermutation(str,i-1,ans);
            swap(str[i],str[j]);
        }
    }
    vector<string> permutation(string& S)
    {
        //Your code here
        vector<string> ans;
        int i=S.length()-1;
        getAllPermutation(S,i,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends