class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0;
        vector<int> mods = vector<int>(n+1);
        vector<int> cnts = vector<int>(n+1);
        map<int, int> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++) {
            mods[i+1] = (nums[i] % modulo) == k;
            cnts[i+1] = cnts[i] + mods[i+1];
            ans += mp[ (cnts[i+1] - k + modulo) % modulo];
            mp[cnts[i+1]%modulo]++;
        }
        
        return ans;
    }
};