class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int i : nums) {
            sum += i;
        }
        long long l = 0;
        int ans = 0;
        for(int i=0;i<nums.size() - 1;i++) {
            l += nums[i];
            long long r =  sum - l;
            if(l >= r) ans++;
        }
        return ans;
    }
};