class Solution {
public:
    int cnt[100001] = {0,};
    int minSetSize(vector<int>& arr) {
        for(int i:arr) cnt[i]++;
        sort(arr.begin(), arr.end(), [&](int u, int v){
            if(cnt[u]==cnt[v]) return u < v;
            return cnt[u] > cnt[v];
        });
        int cnt = 1;
        int prev = arr[0];
        for(int i:arr) cout<<i << ' ';
        for(int i=1;i<arr.size();++i) {
            if(i >= arr.size() / 2) {
                return cnt;
            }
            if(prev!=arr[i]){
                ++cnt;
                prev = arr[i];
            }
        }
        return 0;
    }
};
