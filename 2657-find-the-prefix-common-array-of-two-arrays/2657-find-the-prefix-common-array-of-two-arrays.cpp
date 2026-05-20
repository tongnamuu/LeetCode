class Solution {
public:
    int count(long long x) {
        if(x==0L) return 0;
        long long cnt = 0;
        while(x) {
            if(x&1L) cnt++;
            x>>=1;
        }
        return cnt;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        long long x = 0L;
        long long y = 0L;
        for(int i=0;i<n;i++) {
            x |= (1L<<A[i]);
            y |= (1L<<B[i]);
            ans[i] = count(x&y);
        }
        return ans;
    }
};