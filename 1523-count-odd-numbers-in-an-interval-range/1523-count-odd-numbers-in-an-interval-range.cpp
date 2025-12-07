class Solution {
public:
    int countOdds(int low, int high) {
        if(low>0) low -= 1;
        int cnt1 = low - low / 2;
        int cnt2 = high - high / 2;
        return cnt2 - cnt1;
    }
};