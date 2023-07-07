class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        vector<bool> prime(n,true);
        int count=0;
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
                int j=i*2;
                while(j<n){
                    prime[j]=false;
                    j+=i;
                }
            }
        }
        return count;
    }
};