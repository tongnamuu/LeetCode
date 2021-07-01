class Solution {
public:
    int toNum(string& s) {
        int num = 0;
        for(char ch : s) {
            num<<=1;
            num+=ch-'0';
        }
        return num;
    }
    vector<int> grayCode(int n) {
        if(n==1){
            vector<int> ans = {0, 1};
            return ans;
        }
        vector<string>ans = {"0", "1"};
        int cnt = 1;
        while(cnt<n) {
            vector<string>temp;
            for(string& s : ans) {
                temp.push_back("0" + s);
            }
            for(int i=ans.size()-1;i>=0;--i){
                temp.push_back("1" + ans[i]);
            }
            ++cnt;
            ans = temp;
        }
        vector<int>res;
        for(string& s : ans) {
            //cout<<s<<'\n';
            int num = toNum(s);
            res.push_back(num);
        }
        return res;   
    }
};