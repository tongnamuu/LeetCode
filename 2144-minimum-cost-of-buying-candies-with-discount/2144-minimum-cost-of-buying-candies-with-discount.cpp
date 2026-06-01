class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int i = n - 1;
        int j = 0;
        int ans = 0;
        while(i>=0) {
            if(j<2) {
              ans += cost[i];
              i--;
              j++;
            } else {
                i--;
                j=0;
            }
        }
        return ans;
    }
};