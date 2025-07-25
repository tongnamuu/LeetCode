class Solution {
    public int maxSum(int[] nums) {
        int[] check = new int[300];
        int ans = 0;
        int count = 0;
        int max = nums[0];
        for(int i : nums) {
            if(check[i+100] == 0 && i > 0) {
                ans += i;
                check[i+100] = 1;
                count++;
            }
            max = Math.max(max, i);
        }
        if(count>0) {
            return ans;
        }
        return max;
    }
}