class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i: nums) {
            ans += isEvenDigit(i);
        }
        return ans;
    }
    int isEvenDigit(int x) {
        if(x==0) return 1;
        int a = 0;
        while(x) {
            x /= 10;
            a++;
        }
        return a%2 == 0;
    }
};