class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        long long ans = 0;
        vector<map<long long, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long dif = (long long)A[i] - A[j];
                int sum = 0;
                if (cnt[j].find(dif) != cnt[j].end()) {
                    sum = cnt[j][dif];
                }
                cnt[i][dif] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};
