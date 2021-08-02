class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>>p(n);
        for(int i=0;i<n;++i){
            p[i].first = nums[i];
            p[i].second = i;
        }
        sort(p.begin(), p.end());
        vector<int>ans(2);
        for(int i=0;i<n;++i) {
            int v = target - p[i].first;
            int idx = lower_bound(p.begin()+i+1, p.end(), pair<int ,int>(v, -1)) - p.begin();
            if(idx < n) {
                if(p[idx].first ==  v) {
                    ans[0] = p[i].second;
                    ans[1] = p[idx].second;
                    return ans;
                }
            }   
        }
        return ans;
    }
};
