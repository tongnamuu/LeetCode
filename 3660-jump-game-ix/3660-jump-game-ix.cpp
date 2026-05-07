#define Item pair<int, int>
class Solution {
public:
    void solve(int r, int rightMin, int rightMax, vector<Item>& prevMax, vector<int>& ans, vector<int>& nums) {
        auto [pMax, pivotIndex] = prevMax[r];
        int currMax = pMax <= rightMin ? pMax : rightMax;

        int nextRightMin = min(pMax, rightMin);
        for (int i = pivotIndex; i <= r; ++i) {
            ans[i] = currMax;
            nextRightMin = min(nextRightMin, nums[i]);
        }

        if (pivotIndex == 0) {
            return;
        }

        solve(pivotIndex - 1, nextRightMin, currMax,prevMax, ans, nums);
    }
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<Item> prevMax(n);
        Item prev = {INT_MIN, -1};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > prev.first) {
                prev = {nums[i], i};
            }
            prevMax[i] = prev;
        }

        solve(n - 1, INT_MAX, 0,prevMax,  ans, nums);

        return ans;
    }
};