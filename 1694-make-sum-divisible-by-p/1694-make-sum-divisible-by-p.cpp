class Solution {
public:

    int minSubarray(vector<int>& nums, int p) {
        map<int, int> cnt;
        long total = 0;
        for(int i : nums) total += i;

        if(total%p==0) {
            return 0;
        }
        long remain = total % p;
        cnt[0] = -1;
        long prefixSum = 0;
        int minLength = nums.size();
        for(int i=0;i<nums.size();i++) {
            prefixSum += nums[i];
            int cur = prefixSum % p;
            int target = (cur - remain +p) % p;
            if(cnt.find(target) != cnt.end()) {
                minLength = min(minLength, i - cnt[target]);
            }
            cnt[cur] = i;
        }
        if(nums.size()==minLength) return -1;
        return minLength;
    }
};