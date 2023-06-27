class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int s=0;
        int e=arr.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]==x){
                e=mid;
                break;
            }
            else if(arr[mid]<x)
                s=mid+1;
            else
                e=mid;
        }        
        int n=arr.size();
        int start=e-1;
        int end=e;
        cout<<"Start = "<<start<<endl;
        cout<<"End = "<<end<<endl;
        while(start>=0 && end<n && k>0){
            if(abs(arr[start]-x)<=abs(arr[end]-x)){
                start--;
            }
            else{
                end++;
            }
            k--;
        }
        
        while(start>=0 && k>0){
            start--;
            k--;
        }
        while(end<n && k>0){
            end++;
            k--;
        }
        return vector<int>(arr.begin()+start+1,arr.begin()+end);
    }
};