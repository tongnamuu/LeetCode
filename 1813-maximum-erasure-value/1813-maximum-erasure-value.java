class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int i = 0;
        int j = 1;
        int ans = nums[0];
        int val = nums[0];
        Set<Integer> appear = new HashSet<>();
        appear.add(nums[0]);
        while(i<n && j<n) {
            if(appear.contains(nums[j])) {
                ans = Math.max(ans, val);
                val -= nums[i];
                appear.remove(nums[i]);
                i++;
            } else {
                appear.add(nums[j]);
                val += nums[j];
                ans = Math.max(ans, val);
                j++;  
            }
        }

        return ans;
    }
}