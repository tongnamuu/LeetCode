class Solution {
public:
    int d[1001][1001];
    int rev[1001];
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> idxNums(n);
        for(int i=0;i<n;i++) {
            idxNums[i] = {i, nums[i]};
        }
        sort(idxNums.begin(), idxNums.end(), [](const pair<int,int>& u , const pair<int,int>& v) {
            if(u.second == v.second) {
                return u.first < v.first;
            } else {
                return u.second > v.second;
            }
        });
        sort(idxNums.begin(), idxNums.begin() + k);
        vector<int>ans(k);
        for(int i=0;i<k;i++) {
            ans[i] = idxNums[i].second;
        }
        return ans;
    }
};