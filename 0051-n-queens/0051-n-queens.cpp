class Solution {
public:
    
    unordered_map<int,bool> left;
    
    unordered_map<int,bool> lefttop;
    
    unordered_map<int,bool> leftbottom;
    
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
        
        /*
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
        */
        
        // to optimise isSafe function we use map of O(1) time complexity
        if(left[row] || lefttop[n-1+row-col] || leftbottom[row+col]){
            return false;
        }
        return true;
    }
    
    void solve(vector<vector<int>>& arr,int& n,int col,vector<vector<string>>& ans){
        if(col>=n){
            saveAns(arr,n,ans);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(arr,row,col,n)){
                
                left[row]=true;
                lefttop[n-1+row-col]=true;
                leftbottom[row+col]=true;
                
                arr[row][col]='Q';
                solve(arr,n,col+1,ans);
                
                //backtract condition
                arr[row][col]='.';
                
                left[row]=false;
                lefttop[n-1+row-col]=false;
                leftbottom[row+col]=false;
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