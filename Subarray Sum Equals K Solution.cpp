class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if (!nums.size())
            return 0;
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
            cout << sum[i] << ' ';
        }
        map<int, int> cnt;
        cnt[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans += cnt[sum[i] - k];
            cnt[sum[i]]++;
        }
        return ans;
    }
};