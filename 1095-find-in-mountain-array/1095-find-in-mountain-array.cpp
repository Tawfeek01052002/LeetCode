/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &arr){
        int n=arr.length();
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        
        while(s<e){
            if(arr.get(mid)<arr.get(mid+1)){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    int found(MountainArray &arr,int s,int e,int target,bool left){
        int mid=s+(e-s)/2;
        
        while(s<=e){
            if(arr.get(mid)==target)
                return mid;
            else if(arr.get(mid)<target && left)
                s=mid+1;
            else if(arr.get(mid)>target && !left)
                s=mid+1;
            else
                e=mid-1;
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int peak=findPeak(arr);
        // cout<<"peak = "<<peak;
        int index=found(arr,0,peak,target,true);
        // cout<<" Index = "<<index;
        if(index!=-1)
            return index; 
        else{
            index=found(arr,peak,arr.length()-1,target,false);
            // cout<<" Index = "<<index;
            if(index!=-1)
                return index;
            else
                return -1;
        }
        return -1;
        
    }
};