class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        map<int, int> count;

        int max_v = -1;
        for(int i=0;i<k;i++) {
            count[nums[i]]++;         
        }
        vector<int> temp{nums.begin(), nums.begin() + k};
        sort(temp.begin(), temp.end(), [&](const int u, const int v){
            if(count[u] == count[v]) {
                return u > v;
            }
            return count[u] > count[v];
        });
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        for(int i: temp) {
            cout<<i<<' '<<count[i]<<'\n';
        }
        int v = 0;
        for(int i=0;i<min(x, (int)temp.size());i++) {
            v += temp[i] * count[temp[i]];
        }
        ans.push_back(v);
        for(int i=k;i<nums.size();i++) {
            count[nums[i-k]]--;
            count[nums[i]]++;
            vector<int> temp{nums.begin() + i - k + 1, nums.begin() + i + 1};
            sort(temp.begin(), temp.end(), [&](const int u, const int v){
                if(count[u] == count[v]) {
                    return u > v;
                }
                return count[u] > count[v];
            });
            temp.erase(unique(temp.begin(), temp.end()), temp.end());
            int v = 0;
            for(int j=0;j<min(x, (int)temp.size());j++) {
                v += temp[j] * count[temp[j]];
            }
            ans.push_back(v);
        }
        return ans;
    }
};