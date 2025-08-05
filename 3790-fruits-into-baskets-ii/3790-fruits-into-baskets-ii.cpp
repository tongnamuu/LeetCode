class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //sort(fruits.begin(), fruits.end());
        //sort(baskets.begin(), baskets.end());
        int n = fruits.size();
        vector<int>used(n, 0);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int unmatched = 1;
            for(int j=0;j<n;j++) {
                if(!used[j] && fruits[i] <= baskets[j]) {
                    used[j] = 1;
                    unmatched = 0;
                    break;
                }
            }
            ans += unmatched;
        }
        return ans;
    }
};