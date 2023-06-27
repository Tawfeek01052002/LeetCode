class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        int start=0;
        int end=n-1;
        
        while(end-start>=k){
            if(abs(arr[start]-x)>abs(arr[end]-x)){
                start++;
            }
            else end--;
        }
        // Declaring new vector 
        vector<int> vect2; 
  
        // Copying vector by copy function 
        copy(arr.begin()+start, arr.begin()+start+k, back_inserter(vect2)); 
        return vect2;
        
    }
};