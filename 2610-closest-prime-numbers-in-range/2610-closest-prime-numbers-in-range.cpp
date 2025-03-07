class Solution {
public:
    int check[1000001];
    vector<int> closestPrimes(int left, int right) {
        check[1] = 1;
        vector<int> primes;
        for(int i=2;i<=right;i++) {
            if (check[i]) continue;
            if(i>=left && i <= right) primes.push_back(i);
            for(int j=i+i;j<=right;j+=i) {
                check[j] = true;
            }
        }
        vector<int>ans = {-1, -1};
        if(primes.size() < 2) {
            return ans;
        }
        ans[0] = primes[0];
        ans[1] = primes[1];
        int prev = primes[1] - primes[0];
        for(int i=1;i<primes.size() -1;i++) {
            if(primes[i+1] - primes[i] < prev) {
                ans[0] = primes[i];
                ans[1] = primes[i+1];
                prev = primes[i+1] - primes[i];
            }
        }
        return ans;
    }
};