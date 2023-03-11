class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int n=arr.size();
        int sum=0,max_sum=INT_MIN;
        for(int i=0;i<n;i++){
            if(sum<0)
                sum=0;
            sum+=arr[i];
            if(sum>max_sum)
                max_sum=sum;
        }
        return max_sum;
    }
};