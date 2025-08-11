class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long MOD = 1000000007L;
        int m = queries.size();
        vector<long long> temp;
        pow2(n, temp);
        cout<<'\n';
        vector<int>ans(m);
        for(int i=0;i<m;i++) {
            long long res = 1;
            int s = queries[i][0];
            int e = queries[i][1];
            long long val = 1;
            for(int j=s;j<=e;j++) {
                val *= temp[j];
                val %= MOD;
            }
            ans[i] = val;  
        }
        return ans;
    }
    void pow2(int n, vector<long long>& vec) {
        long long temp = 1L;
        while(n) {
            if (n&1) {
                vec.push_back(temp);
            }
            temp *= 2;
            n >>= 1;
        }
    }
};