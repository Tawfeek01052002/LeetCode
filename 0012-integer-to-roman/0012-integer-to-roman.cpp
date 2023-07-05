class Solution {
public:
    
    //we are handling for this case
    // I can be placed before V (5) and X (10) to make 4 and 9. 
    // X can be placed before L (50) and C (100) to make 40 and 90. 
    // C can be placed before D (500) and M (1000) to make 400 and 900.
    // T.C.=O(n) S.C.=O(1)
    string intToRoman(int num) {
        string ans="";
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int arr[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        //using for each loop to get map element in order
        for(int i=0;i<13;i++){
            while(num>=arr[i]){
                ans+=roman[i];
                num-=arr[i];
            }
        }
        return ans;
        
    }
};