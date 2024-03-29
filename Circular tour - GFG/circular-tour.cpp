//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Same as Gas Station on Leetcode
       
       int remainingpetrol=0;
       int petrolneeded=0;
       int startStation=0;
       
       for(int i=0;i<n;i++){
           remainingpetrol+=p[i].petrol-p[i].distance;
           
           if(remainingpetrol<0){
               petrolneeded+=remainingpetrol;
               remainingpetrol=0;
               startStation=i+1;
           }
       }
       
       if(petrolneeded+remainingpetrol>=0){
           return startStation;
       }
       else{
           return -1;
       }
       
       
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends