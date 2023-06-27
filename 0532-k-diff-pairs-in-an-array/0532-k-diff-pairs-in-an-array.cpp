class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        //Brute force approach
        //T.C.=O(n^2) S.C.=O(n)
//         int n=nums.size();
//         int count=0;
//         set<pair<int,int>> s;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if(abs(nums[i]-nums[j])==k && s.count({nums[i],nums[j]})==0 && s.count({nums[j],nums[i]})==0){
//                     s.insert({nums[i],nums[j]});
//                     count++;
//                 }
                    
//             }   
//         }
//         return count;
        
        //Sightly Optimized
        // using STL Sort and Two pointer approach
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<pair<int,int>> s;
        int i=0;
        int j=1;
        while(j<n){
            int diff=abs(nums[j]-nums[i]);
            if(diff==k){
                s.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff>k)
                i++;
            else
                j++;
            
            if(i==j) j++;
        }
        return s.size();
    }
};