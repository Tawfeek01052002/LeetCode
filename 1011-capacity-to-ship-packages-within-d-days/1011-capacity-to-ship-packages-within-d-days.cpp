class Solution {
public:
    int isPossibleSolution(vector<int>& weights, int days,int ans){
        int c=1;
        int weightSum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>ans){
                return false;
            }
            
            if(weights[i]+weightSum<=ans){
                weightSum+=weights[i];
            }
            else{
                c++;
                weightSum=weights[i];
                if(c>days)
                    return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        int end=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossibleSolution(weights,days,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};