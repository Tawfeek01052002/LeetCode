class Solution {
public:
    void saveAns(vector<vector<int>>& arr,int& n,vector<vector<string>>& ans){
        vector<string> tempstr;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                temp.push_back(arr[i][j]);
            }
            tempstr.push_back(temp);
        }
        ans.push_back(tempstr);
    }
    
    bool isSafe(vector<vector<int>>& arr,int row,int col,int n){
        
        int i=row;
        int j=col;
        
        while(j>=0){
            if(arr[i][j--]=='Q'){
                return false;
            }
        }
        
        i=row;
        j=col;
        while(i>=0 && j>=0){
            if(arr[i--][j--]=='Q'){
                return false;
            }
        }
        
        i=row;
        j=col;
        while(i<n && j>=0){
            if(arr[i++][j--]=='Q'){
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<vector<int>>& arr,int& n,int col,vector<vector<string>>& ans){
        if(col>=n){
            saveAns(arr,n,ans);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(arr,i,col,n)){
                arr[i][col]='Q';
                solve(arr,n,col+1,ans);
                
                //backtract condition
                arr[i][col]='.';
            }   
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> arr(n,vector<int>(n,'.'));
        int col=0;
        vector<vector<string>> ans;
        solve(arr,n,col,ans);
        return ans;
    }
};