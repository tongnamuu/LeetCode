class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<int>cnt(1001);
        if(skill.size()==2) {
            return skill[0] * skill[1];
        }
        int total = 0;
        for(int i : skill) {
            total += i;
            cnt[i]++;
        }
        int teamCnt = skill.size() / 2;
        if(total % teamCnt != 0) {
            return -1;
        }
        int val = total / teamCnt;
        long long ans = 0;
        for(int i:skill) {
            if(cnt[i]>0) {
                int target = cnt[val - i];
                if(target != cnt[i]) {
                    return -1;
                }
                ans += (long long) i * (val - i);
                cnt[i]--;
                cnt[val-i]--;
            }
        }
        return ans;
    }
};