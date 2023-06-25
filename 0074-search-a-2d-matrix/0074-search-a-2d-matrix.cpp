class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRow=matrix.size();
        int totalCol=matrix[0].size();
        int start=0;
        int end=(totalRow*totalCol)-1;
        int mid=0;
        int row,col;
        while(start<=end){
            mid=start+(end-start)/2;
            row=mid/totalCol;
            col=mid%totalCol;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return false;
    }
};