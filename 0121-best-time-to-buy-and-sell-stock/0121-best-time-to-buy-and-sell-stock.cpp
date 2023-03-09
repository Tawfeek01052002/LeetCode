class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int minele=prices[0];
        for(int i=0;i<prices.size();i++){
            minele=min(minele,prices[i]);
            if((prices[i]-minele)>maxprofit){
                maxprofit=prices[i]-minele;
            }
        }
        
        return maxprofit;
    }
};