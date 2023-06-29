class Solution {
public:
    int isPossibleSolution(vector<int>& pos, int m,int ans){
        int c=1;
        int prev=pos[0];
        for(int i=0;i<pos.size();i++){
            if(pos[i]-prev>=ans){
                c++;
                prev=pos[i];
            }
            if(c==m){
                return true;
            }
        }
        return false;
    }
    
    //Similar to - Aggressive Cow
    int maxDistance(vector<int>& pos, int m) {
        
        sort(pos.begin(),pos.end());
        int start=0;
        int end=pos[pos.size()-1]-pos[0];
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossibleSolution(pos,m,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};