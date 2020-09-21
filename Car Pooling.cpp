class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001] = {
            0,
        };
        for (auto& t : trips) {
            int from = t[1];
            int to = t[2];
            for (int i = t[1]; i < t[2]; ++i) {
                d[i] += t[0];
                if (d[i] > capacity) return false;
            }
        }
        return true;
    }
};
