class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size(),-1);
        
        stack<int> s;
        
        for(int i=cars.size()-1;i>=0;i--){
            
            //check if the car ahead of current car is faster ?
            while(!s.empty() && cars[s.top()][1]>= cars[i][1]){
                s.pop();
            }
            
            while(!s.empty()){
                double coliTime=(double) (cars[s.top()][0]-cars[i][0])/ (cars[i][1] - cars[s.top()][1]);
                if(ans[s.top()] ==-1 || coliTime<= ans[s.top()]){
                    ans[i]=coliTime;
                    break;
                }
                else{
                    s.pop();
                }
            }
            s.push(i);
        }
        return ans;
    }
};