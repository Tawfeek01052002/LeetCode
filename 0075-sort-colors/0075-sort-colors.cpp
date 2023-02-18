class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //Using Sort function
        // sort(nums.begin(),nums.end());
        
        //Using Counting
//         int zero=0,one=0,two=0;
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0)
//                 zero++;
//             else if(nums[i]==1)
//                 one++;
//             else
//                 two++;
//         }
//         int i=0;
//         while(zero-->0)
//             nums[i++]=0;
//         while(one-->0)
//             nums[i++]=1;
//         while(two-->0)
//             nums[i++]=2;
        
        //Dutch National Flag 
        //Using 3 Pointers
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==1)
                m++;
            else if(nums[m]==2)
                swap(nums[m],nums[h--]);
            else
                swap(nums[l++],nums[m++]);
        }
        
    }
};