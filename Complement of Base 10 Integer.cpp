class Solution {
   public:
    int bitwiseComplement(int N) {
        int x = 1;
        while ((1 << x) <= N) ++x;
        return (1 << x) - 1 - N;
    }
};
