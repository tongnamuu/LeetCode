class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int> counts;
       for(int c : costs) {
        counts[c]++;
       }
       int ans = 0;
       for(auto i=counts.begin(); i!=counts.end();i++) {
        int c = i -> first;
        int cnt = i -> second;
        int q = coins / c;
        int minusCount = min(cnt, q);
        coins -= minusCount * c;
        ans += minusCount;
       }
       return ans;
    }
};