class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<int>temp(2*n);
        for(int i=0;i<n;++i) {
            temp[i] = 0;
        }
        for(int i=n;i<2*n;++i) {
            temp[i] = 1;
        }
        vector<string>ans;
        do{
            stack<int> s;
            bool ok = true;
            for(int i=0;i<2*n;++i) {
                if(!temp[i]) {
                    s.push(0);
                } else {
                    if(s.empty()) {
                        ok = false;
                        break;
                    } else {
                        s.pop();
                    }
                }
            }
            if(ok) ok = s.empty();
            if(ok) {
                string str;
                for(int i=0;i<2*n;++i) {
                    if(!temp[i]) {
                        str+='(';
                    } else {
                        str += ')';
                    }
                }
                ans.push_back(str);
            }
            
        }while(next_permutation(temp.begin(), temp.end()));
        return ans;
    }
};
