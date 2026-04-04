class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = rows;
        int m = encodedText.length() / n;
        string ans;
        for(int s=0;s<m;s++) {
            for(int i=0;i<n;i++) {
                int j = i + s;
                int idx = i*m + j;
                if(idx<encodedText.length()) {
                    ans += encodedText[idx];
                } 
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};