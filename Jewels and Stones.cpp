class Solution {
   public:
    int numJewelsInStones(string J, string S) {
        sort(S.begin(), S.end());
        int ans = 0;
        for (char c : J) {
            ans += upper_bound(S.begin(), S.end(), c) - lower_bound(S.begin(), S.end(), c);
        }
        return ans;
    }
};