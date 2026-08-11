class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0];
        int prev = nums[0];
        int n = nums.size();
        int sum = nums[0];
        set<int> st;
        for(int i : nums) st.insert(i);
        int len = 1;
        int maxlen = 1;
        for(int i=1;i<n;i++) {
            if(nums[i]==prev+1) {
                sum += nums[i];
                len++;
                if(len>maxlen) {
                    maxlen = len;
                    ans = max(ans, sum);
                }
            } else {
                break;
            }
            prev = nums[i];
        }
        while(st.find(ans)!=st.end()) {
            ans++;
        }
        return ans;
    }
};