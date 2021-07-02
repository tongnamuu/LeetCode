class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](const int& u, const int& v){
            int d1 = abs(u-x);
            int d2 = abs(v-x);
            if(d1==d2) return u < v;
            return d1 < d2;
        });
        vector<int>ans(arr.begin(), arr.begin()+k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
