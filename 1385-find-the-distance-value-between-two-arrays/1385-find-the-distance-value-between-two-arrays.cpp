class Solution {
public:
    int solve(int x, vector<int>& a, int d) {
        for(int i : a) {
            int diff = abs(i-x);
            if(diff<=d) return 0;
        }
        return 1;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int i: arr1) {
            ans += solve(i, arr2, d);
        }
        return ans;
    }
};