class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        
        //T.C.=O(n) S.C.=O(1)
        int diff=0;
        int minSofar=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minSofar)
                minSofar=prices[i];
            diff=max(diff,prices[i]-minSofar);
        }
        return diff;
    }
};