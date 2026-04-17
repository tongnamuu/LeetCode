class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        int ans = 0;
        while(x) {
            ans *= 10;
            ans += x%10;
            x /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 2147483647;
        map<int, pair<int, int>> idxMap;
        for(int i=0;i<n;i++) {
            auto x = idxMap.find(nums[i]);
            if(x==idxMap.end()) {
                idxMap[nums[i]] = {i,i};
            } else {
                x -> second.first = min(x -> second.first, i);
                x -> second.second = max(x -> second.first, i);
            }
        }
        for(int i=0;i<n;i++) {
            int target = reverse(nums[i]);
            auto y = idxMap.find(target);
            if(y!=idxMap.end()) {
                int r1 = y->second.first - i;
                int r2 = y->second.second - i;
                if(r1 > 0) ans = min(ans, r1);
                if(r2 > 0) ans = min(ans, r2);
            }
        }
        if(ans == 2147483647) return -1;
        return ans;
    }
};