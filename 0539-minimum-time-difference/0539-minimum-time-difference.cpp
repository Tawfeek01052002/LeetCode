class Solution {
public:
    int findMinDifference(vector<string>& time) {
        int n=time.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            int hh=stoi(time[i].substr(0,2));
            int mm=stoi(time[i].substr(3,5));
            int minutes=hh*60+mm;
            arr.push_back(minutes);
        }
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++){
            mini=min(mini,arr[i]-arr[i-1]);
        }
        mini=min(mini,1440+arr[0]-arr[arr.size()-1]);
        return mini;
    }
};