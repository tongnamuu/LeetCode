class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = 1;
        vector<int> ans(nums.size());
        for (int i = 0; i < ans.size(); ++i)
        {
            ans[i] = n;
            n *= nums[i];
        }
        n = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            ans[i] *= n;
            n *= nums[i];
        }

        return ans;
    }
};