class Solution {
public:
    //Checking that is it a PossibleSolution from the search space  
    bool isPossibleSolution(vector<int> arr,int k,int ans){
        int n=arr.size();
        int c=1;
        int pageSum=0;
        if(arr.size()<k)
            return false;
        for(int i=0;i<n;i++){
            if(arr[i]>ans)
                return false;
            if(pageSum+arr[i]<=ans){
                pageSum+=arr[i];
            }
            else{
                c++;
                pageSum=arr[i];
                if(c>k)
                    return false;
            }
        }
        return true;
    }
    
    
    //Book Allocation Problem
    int splitArray(vector<int>& nums, int k) {
        //Defining Search Space i.e. 0---sumofElementsofArray
        int start=0;
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossibleSolution(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};