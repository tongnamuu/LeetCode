class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int prev = 0;
        for(int i=0;i<n;i++) {
            prev = prev + gain[i];
            ans = max(ans, prev);
        }
        return ans;
    }
};