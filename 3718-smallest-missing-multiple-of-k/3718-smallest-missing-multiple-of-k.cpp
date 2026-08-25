class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans = 1000000000;
        bool find = false;
        set<int>st(nums.begin(), nums.end());
        for(int i: nums) {
            if(i==k) find = true;
            if(i%k==0) {
                int target = (i+k);
                while(st.find(target)!=st.end()) {
                    target += k;
                }
                ans = min(ans, target);
            }
        }
        if(ans==1000000000 || !find) return k;
        return ans;
    }
};