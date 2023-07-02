class Solution {
public:
    string trim(string s){
        int index=s.find(" ");
        while(index!=string::npos){
            s.erase(index,1);
            index=s.find(" ");
        }
        return s;
    }
    
    vector<string> split(string s){
        int i=0;
        int j=1;
        vector<string> arr;
        while(j<s.length()){
            if(s[j]==' '){
                string sub=trim(s.substr(i,j-i+1));
                if(sub[0]!=NULL)
                    arr.push_back(sub);
                i=j;
            }
            j++;
        }
        string sub=trim(s.substr(i,j-i+1));
        if(sub[0]!=NULL)
            arr.push_back(sub);
        return arr;
    }
        
    string reverseWords(string s) {
        vector<string> arr=split(s);
        cout<<arr.size()<<endl;
        string ans="";
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            swap(arr[start++],arr[end--]);
        }
        for(int i=0;i<arr.size();i++){
            ans=ans+arr[i]+" ";
        }
        ans.pop_back();
        return ans;
    }
};