class Solution {
public:
    
    //Checking that this minimum weight is possible or not
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
    
    
    //Using Book Allocation Problem
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int e=0;
        for(int i=0;i<weights.size();i++){
            e+=weights[i];
        }
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossibleSolution(weights,days,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};