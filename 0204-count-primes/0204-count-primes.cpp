class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    int countPrimes(int n) {
        
        //T.C.=O(n √n) S.C.=O(1) //TLE
        // if(n<=1)
        //     return 0;
        // int count=0;
        // for(int i=2;i<n;i++){
        //     if(isPrime(i))
        //         count++;
        // }
        // return count;
        
        //sieve of eratosthenes
        if(n<2)
            return 0;
        vector<bool> arr(n,true);
        arr[0]=false;
        arr[1]=false;
        for(int i=2;i<n;i++){
            if(!arr[i])
                continue;
                
            int j=2;
            while((i*j)<n){
                arr[i*j]=false; 
                j++;
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i])
                count++;
        }
        return count;
    }
};