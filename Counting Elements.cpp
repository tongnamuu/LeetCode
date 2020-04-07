class Solution {
   public:
    int countElements(vector<int>& arr) {
        vector<int> d(1001);
        for (int i = 0; i < arr.size(); ++i) {
            d[arr[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < 1000; ++i) {
            if (d[i + 1]) {
                ans += d[i];
            }
        }
        return ans;
    }
};