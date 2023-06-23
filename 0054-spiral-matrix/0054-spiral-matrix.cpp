class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        int rowstart=0;
        int rowend=row-1;
        int colstart=0;
        int colend=col-1;
        vector<int> arr;
        int nele=row*col;
        int count=0;
        while(count<nele){
            for(int i=colstart;i<=colend && count<nele;i++){
                arr.push_back(matrix[rowstart][i]);
                count++;
            }  
            rowstart++;
            for(int i=rowstart;i<=rowend && count<nele;i++){
                arr.push_back(matrix[i][colend]);
                count++;
            } 
            colend--;
            for(int i=colend;i>=colstart && count<nele;i--){
                arr.push_back(matrix[rowend][i]);
                count++;
                
            } 
            rowend--;
            for(int i=rowend;i>=rowstart && count<nele;i--){
                arr.push_back(matrix[i][colstart]);
                count++;
                
            }  
            colstart++;
        }
        return arr;
    }
};