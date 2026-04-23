class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        map<int, pair<long long, long long>> m;
        for(int i=0;i<n;i++) {
            pair<long long, long long>& x = m[nums[i]];
            ans[i] += (abs(x.first*i - x.second));
            x.first += 1L;
            x.second += i;
        }
        for(int i=0;i<n;i++) {
            pair<long long, long long>& x = m[nums[i]];
            ans[i] += (abs(x.first*i - x.second));
            x.first -= 1;
            x.second -= i;
        }
        return ans;
    }
};
