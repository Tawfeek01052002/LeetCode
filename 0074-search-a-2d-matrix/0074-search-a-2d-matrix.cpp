class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //Using Binary Search
        int n=matrix.size();
        int m=matrix[0].size();
        int start=0;
        int end=(n*m)-1;
        int r,c,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            r=mid/m;
            c=mid%m;
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]>target){
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return false;
    }
};