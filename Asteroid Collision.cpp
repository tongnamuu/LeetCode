class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int x : asteroids) {
            bool deleted = false;
            while (x < 0 && !ans.empty() && ans.back() > 0) {
                int std = ans.back();
                if (std + x == 0) {
                    ans.pop_back();
                    deleted = true;
                    break;
                } else if (std + x < 0) {
                    ans.pop_back();
                } else {
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
