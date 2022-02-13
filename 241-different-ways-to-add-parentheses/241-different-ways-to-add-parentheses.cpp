class Solution {
public:
    int to_int(string& s) {
        int ans = 0;
        for(char c : s) {
            ans *= 10;
            ans += (c-'0');
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        int n=expression.size();
        for(int i = 0; i < n; ++i){
            if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){                
                vector<int> x=diffWaysToCompute(expression.substr(0,i));
                vector<int> y=diffWaysToCompute(expression.substr(i+1));
                for(int a:x) {
                    for(int b:y){
                        if(expression[i]=='+')ans.push_back(a+b);
                        else if(expression[i]=='-')ans.push_back(a-b);
                        else ans.push_back(a*b);
                    }
                }
            }
        }
        if(ans.empty())ans.push_back(to_int(expression));
        return ans;
    }
};