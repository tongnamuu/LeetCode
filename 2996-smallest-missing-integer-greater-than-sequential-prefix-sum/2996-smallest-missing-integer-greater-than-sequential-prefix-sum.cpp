class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int sum = nums[0];
        set<int> st;
        for(int i : nums) st.insert(i);
        for(int i=1;i<n;i++) {
            if(nums[i]==nums[i-1]+1) {
                ans += nums[i];
            } else {
                break;
            }
        }
        while(st.find(ans)!=st.end()) {
            ans++;
        }
        return ans;
    }
};