class Solution {
public:
    
    void maxPro(vector<int>& arr,int& diff,int& mini,int i){
        if(i>=arr.size()){
            return;
        }
        if(arr[i]<mini)
            mini=arr[i];
        else
            diff=max(diff,arr[i]-mini);
        
        maxPro(arr,diff,mini,i+1);
    }
    
    int maxProfit(vector<int>& prices) { 
        
        //T.C.=O(n) S.C.=O(1)
        // int diff=0;
        // int minSofar=prices[0];
        // for(int i=1;i<prices.size();i++){
        //     if(prices[i]<minSofar)
        //         minSofar=prices[i];
        //     else diff=max(diff,prices[i]-minSofar);
        // }
        // return diff;
        
        //using recursion
        int diff=0;
        int mini=prices[0];
        int i=0;
        maxPro(prices,diff,mini,i);
        return diff;
    }
};