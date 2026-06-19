class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>x(n+1);
        int ans = 0;
        for(int i=0;i<n;i++) {
            x[i+1] = x[i] + gain[i];
            ans = max(ans, x[i+1]);
        }
        return ans;
    }
};