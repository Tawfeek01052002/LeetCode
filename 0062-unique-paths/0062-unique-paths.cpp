class Solution {
public:
    void possiblePaths(int m,int n,int i,int j,int& count){
        
        if(i>m || j>n){
            return;
        }
        
        if(i==m && j==n){
            count++;
            return;
        }
        
        //right
        possiblePaths(m,n,i,j+1,count);
        
        // down
        possiblePaths(m,n,i+1,j,count);
    }
    int uniquePaths(int m, int n) {
        // int count=0;
        // int i=1;
        // int j=1;
        // possiblePaths(m,n,i,j,count);
        // return count;
        if (m <= 0 || n <= 0) {
        return 0;
    }

    // Calculate the total steps (m-1) + (n-1) and (m-1) to take steps down
    int totalSteps = (m - 1) + (n - 1);
    int downSteps = m - 1;

    // Calculate the combination using factorials
    long long paths = 1;
    for (int i = 1; i <= downSteps; ++i) {
        paths = paths * (totalSteps - downSteps + i) / i;
    }

    return static_cast<int>(paths);
    }
};