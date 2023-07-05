class Solution {
public:
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