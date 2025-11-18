class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size()==1) {
            return bits.back() == 0;
        }
        int n = bits.size();
        int i = 0;
        while(i<n) {
            if(bits[i]==1) {
                if(i==n-2) return false;
                if(i+1<n) {
                    i += 2;
                } else {
                    return false;
                }
            } else {
                i += 1;
            }
        }
        return true;
    }
};