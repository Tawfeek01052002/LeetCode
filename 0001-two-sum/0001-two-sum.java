class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] arr=new int[2];
        Map<Integer,Integer> maps=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(maps.containsKey(target-nums[i])){
                arr[1]=i;
                arr[0]=maps.get(target-nums[i]);
                return arr;
                
            }
            maps.put(nums[i],i);
        }
        return arr;
    }
}