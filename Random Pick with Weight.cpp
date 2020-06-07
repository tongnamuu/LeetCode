class Solution {
   public:
    vector<int> a;
    int sum;
    Solution(vector<int>& w) {
        sum = 0;
        for (int& i : w) {
            sum += i;
            a.push_back(i + (a.size() ? a.back() : 0));
        }
    }

    int pickIndex() {
        int index = rand() % sum;
        return upper_bound(a.begin(), a.end(), index) - a.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */