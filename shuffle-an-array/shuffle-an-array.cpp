class Solution {
public:
    vector<int> a;
    vector<int> b;
    Solution(vector<int>& nums) {
        a = nums;
        b = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return b;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(a.begin(), a.end());
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */