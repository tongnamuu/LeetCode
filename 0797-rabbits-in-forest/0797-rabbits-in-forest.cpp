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
            while(number > 0) {
                number -= (r + 1);
                ans += (r + 1);
            }
        }
        return ans;
    }
};
