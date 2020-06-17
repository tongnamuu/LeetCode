class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (!n || n == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> d(n);
        vector<int> from(n, -1);
        for (int i = 0; i < n; ++i) {
            d[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (d[i] < d[j] + 1) {
                        d[i] = d[j] + 1;
                        from[i] = j;
                    }
                }
            }
        }
        int ans = 0;
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (ans < d[i]) {
                ans = d[i];
                idx = i;
            }
        }
        vector<int> answer;
        while (idx != -1) {
            answer.push_back(nums[idx]);
            idx = from[idx];
        }
        return answer;
    }
};