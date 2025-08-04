class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> cnt;
        int i = 0;
        int j = 1;
        int n = fruits.size();
        cnt[fruits[i]]++;
        int ans = 1;
        while(i<n&&j<n) {
            //cout<<i<<' '<<j<<'\n';
            if(cnt.find(fruits[j]) != cnt.end()) {
                cnt[fruits[j]]++;
                j++;
                int temp = 0;
                for(auto x = cnt.begin();x != cnt.end(); x++) {
                    temp += x -> second;
                }
                ans =max(ans, temp);
            } else {
                if(cnt.size()>= 2) {
                    int x = cnt[fruits[i]];
                    if(x==1) {
                        cnt.erase(fruits[i]);
                    } else {
                        cnt[fruits[i]]--;
                    }
                    i++;
                } else {
                    cnt[fruits[j]]++;
                    j++;
                    int temp = 0;
                    for(auto x = cnt.begin();x != cnt.end(); x++) {
                        temp += x -> second;
                    }
                    ans =max(ans, temp);
                }

            }
        }
        return ans;
    }
};