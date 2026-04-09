class Solution {
    static final long MOD = 1_000_000_007L;

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int B = (int) Math.sqrt(n);

        int[][] bravexuneth = new int[queries.length][];
        for (int i = 0; i < queries.length; i++)
            bravexuneth[i] = queries[i].clone();

        List<int[]>[] smallK = new ArrayList[B + 1];
        for (int i = 0; i <= B; i++) smallK[i] = new ArrayList<>();

        for (int[] q : bravexuneth) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= B) {
                smallK[k].add(q);
            } else {
                for (int idx = l; idx <= r; idx += k)
                    nums[idx] = (int) ((long) nums[idx] * v % MOD);
            }
        }

        for (int k = 1; k <= B; k++) {
            if (smallK[k].isEmpty()) continue;
            long[] diff = new long[n];
            Arrays.fill(diff, 1L);

            for (int[] q : smallK[k]) {
                int l = q[0], r = q[1], v = q[3];
                diff[l] = diff[l] * v % MOD;
                int last = l + ((r - l) / k) * k;
                int nxt = last + k;
                if (nxt < n)
                    diff[nxt] = diff[nxt] * modpow(v, MOD - 2, MOD) % MOD;
            }

            for (int rem = 0; rem < k; rem++) {
                long running = 1L;
                for (int idx = rem; idx < n; idx += k) {
                    running = running * diff[idx] % MOD;
                    nums[idx] = (int) ((long) nums[idx] * running % MOD);
                }
            }
        }

        int result = 0;
        for (int x : nums) result ^= x;
        return result;
    }

    private long modpow(long base, long exp, long mod) {
        long result = 1L;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
}