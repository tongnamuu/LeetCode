class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = 250;
        int intervalCount = 400;
        vector<int>interval(intervalCount);
        for(int i=0;i<n;i++) {
            interval[i/m] = max(interval[i/m], baskets[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            int occupied = 0;
            for(int j=0;!occupied && j<intervalCount;j++) {
                if(interval[j] < fruits[i]) continue;
                interval[j] = 0;
                for(int k=0;k<m;k++) {
                    int idx = j*m + k;
                    if(idx>=n) break;
                    if(fruits[i] <= baskets[idx] && !occupied) {
                        baskets[idx] = 0;
                        occupied = 1;
                    }
                    interval[j] = max(interval[j], baskets[idx]);
                }
                break;
            }
            if(!occupied) ans++;
        }

        return ans;
    }
};