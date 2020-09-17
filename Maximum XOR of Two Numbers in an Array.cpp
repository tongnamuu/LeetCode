class Solution {
   public:
    struct Trie {
        int child[2];
        Trie() {
            child[0] = child[1] = -1;
        }
    };
    struct Trie trienode[500000];
    int trie_cnt = 0;

    int findMaximumXOR(vector<int>& nums) {
        int root = trie_cnt++;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int node = root;
            for (int j = 30; j >= 0; --j) {
                int r = ((1 << j) & nums[i]) ? 1 : 0;
                int& next = trienode[node].child[r];
                if (next == -1) next = trie_cnt++;
                node = next;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int node = root;
            int temp = 0;
            for (int j = 30; j >= 0; --j) {
                int r = ((1 << j) & nums[i]) ? 0 : 1;
                if (trienode[node].child[r] != -1) {
                    temp <<= 1;
                    temp |= 1;
                    node = trienode[node].child[r];
                } else {
                    temp <<= 1;
                    node = trienode[node].child[r ^ 1];
                }
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};
