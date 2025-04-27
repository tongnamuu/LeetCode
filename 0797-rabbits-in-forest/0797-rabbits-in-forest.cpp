class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> cnt;
        for(int i:answers) {
            cnt[i]++;
        }
        int ans = 0;
        for(auto i = cnt.begin();i!=cnt.end();i++) {
            int r = i -> first;
            int number = i -> second;
            int x = (number + r) / ( r + 1);
            ans += x * (r + 1);
        }
        return ans;
    }
};
