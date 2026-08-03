class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int total = 0;
        int f1 = 0;
        int f2 = 0;
        int f3 = 0;
        int n = stoneValue.size();
        for(int i=n-1;i>=0;i--) {
            total += stoneValue[i];
            int newF = total - min({f1,f2,f3});
            f3 = f2;
            f2 = f1;
            f1 = newF;
        }
        int diff = f1 - (total - f1);
        if (diff>0) return "Alice";
        else if(diff<0) return "Bob";
        return "Tie";
    }
};