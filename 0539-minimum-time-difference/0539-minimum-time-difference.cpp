class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int> minutes;
        for(int i=0;i<time.size();i++){
            int hh=stoi(time[i].substr(0,2));
            int mm=stoi(time[i].substr(3,2));
            int total_min=hh*60+mm;
            minutes.push_back(total_min);
        }
        sort(minutes.begin(),minutes.end());
        int min_diff=INT_MAX;
        int n=minutes.size();
        for(int i=1;i<n;i++){
            int diff=minutes[i]-minutes[i-1];
            if(diff<min_diff){
                min_diff=diff;
            }
        }
        
        //Edge Test case VVVVIMP
        int lastdiff=minutes[0]+1440-minutes[n-1];
        if(lastdiff<min_diff){
            min_diff=lastdiff;
        }
        return min_diff;
    }
};