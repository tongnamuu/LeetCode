class Solution {
public:
    vector<int> a[200001];
    int specialTriplets(vector<int>& nums) {
        const long long mod = 1000000007L;
        for(int i=0;i<nums.size();i++) {
            a[nums[i]].push_back(i);
        }
        long long zero = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) {
                zero++;
                continue;
            }
            int center = nums[i];
            int find = center * 2;
            int sz = a[find].size();
            if(sz<=1) continue;
            int idx = lower_bound(a[find].begin(), a[find].end(), i) - a[find].begin();
            int up = upper_bound(a[find].begin(), a[find].end(), i) - a[find].begin();
            long long left = idx;
            long long right = sz - up;
            ans += (left * right) % mod;
        }
        ans += zero * (zero - 1) * (zero - 2) / 6;
        ans %= mod;
        return ans;
    }
};