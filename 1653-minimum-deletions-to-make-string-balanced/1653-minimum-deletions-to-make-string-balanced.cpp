class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>bcount(n);
        vector<int>acount(n);

        // a b 형태여야함
        // a 면 a의 마지막 인덱스로 삼고 앞쪽의 b, 뒷쪽의 a 를 날린다.
        // b 면 b의 첫번째 인덱스로 삼아 앞쪽의 b, 뒷쪽의 a 를 날린다
        if(s[0]=='b') {
            bcount[0] = 1;
        }
        if(s[n-1] == 'a') {
            acount[n-1] = 1;
        }
        for(int i=1;i<n;i++) {
            bcount[i] = bcount[i-1] + (s[i]=='b');
        }
        for(int i=n-2;i>=0;i--) {
            acount[i] = acount[i+1] + (s[i]=='a');
        }
        int ans = min(acount[0], bcount[n-1]);
        for(int i=1;i<n-1;i++) {
            int temp = acount[i+1] + bcount[i-1];
            ans = min(ans, temp);
        }
        return ans;
    }
};