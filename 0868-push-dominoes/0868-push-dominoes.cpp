class Solution {
public:
    
    string pushDominoes(string s) {
        int n = s.size();
        vector<int>left(n, -1);
        vector<int>right(n, -1);
        int i = n - 1;
        while(i>=0) {
            if(s[i]=='L') {
                int d = 1;
                while(i>=0&&s[i] !='R') {
                    if(s[i]=='L') {
                        left[i] = 0;
                        d=1;
                    } else {
                        left[i] = d;
                        d++;
                    }
                    i--;
                }
            } else {
                i--;
            }
        }
        i = 0;
        while(i<n) {
            if(s[i]=='R') {
                int d = 1;
                while(i<n&&s[i] !='L') {
                    if(s[i]=='R') {
                        right[i] = 0;
                        i++;
                        d=1;
                    } else {
                        right[i] = d;
                        d++;
                        i++;
                    }
                }
            } else {
                i++;
            }
        }
        string ans;
        for(i=0;i<n;i++) {
            cout<<left[i];
        }
        cout<<'\n';
        for(i=0;i<n;i++) {
            cout<<right[i];
        }
        for(int i=0;i<n;i++) {
            if(left[i]==-1 && right[i] == -1) {
                ans +='.';
            } else if(left[i] != -1 && right[i] ==-1) {
                ans += 'L';
            } else if(left[i] == -1 && right[i] !=-1) {
                ans += 'R';
            } else {
                if(left[i] > right[i]) {
                    ans += 'R';
                } else if(left[i] < right[i]) {
                    ans += 'L';
                } else {
                    ans += '.';
                }
            }
        }
        return ans;
    }

};