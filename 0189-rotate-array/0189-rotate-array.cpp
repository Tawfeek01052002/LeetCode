    class Solution {
    public:
        void reverse(vector<int>&arr,int start,int end){
            while(start<end){
                swap(arr[start],arr[end]);
                start++;
                end--;
            }
        }
        void rotate(vector<int>& arr, int k) {
            // int n=arr.size();
            // if(n==1){
            //     return;
            // }
            // for(int i=n-1,j=k-1;j>=0;i--,j--){
            //     swap(arr[i],arr[j%n]);
            // }
            // if(n&1==1){
            //     for(int i=n-1;i>=k;i--){
            //         swap(arr[k%n],arr[i]);
            //     }
            // }
            
            
            //[1,2,3,4,5,6,7], n = 7, k = 3. Reverse[1,2,3,4] ------->
            //[4,3,2,1,5,6,7], reverse [5, 6, 7] ------> [4, 3, 2, 1, 7, 6, 5], 
            //reverse the whole array ------> [5, 6, 7, 1, 2, 3, 4].
                
            int n=arr.size();
            if(n<2){
                return;
            }
            k=k%arr.size();
            reverse(arr,0,n-k-1);
            reverse(arr,n-k,n-1);
            reverse(arr,0,n-1);

        }
    };