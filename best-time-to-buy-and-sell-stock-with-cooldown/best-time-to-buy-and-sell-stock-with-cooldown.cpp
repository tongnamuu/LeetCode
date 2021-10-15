class Solution {
public:
    int d[5001][3];
    int solve(int idx, int state, vector<int>& price) {
        if(idx>=price.size()) return 0;
        int& ret = d[idx][state];
        if(ret!=-1) return ret;
        if(state == 0) { // 안삿음
            int x = solve(idx+1, 1, price) - price[idx];
            int y = solve(idx+1, 0, price);
            if(x>y) {
                cout<<idx<<"구매\n";
            } else {
    
                cout<<idx<<"안사고 그대로 통과\n";
                
            }
            ret = max(x,y);
        }
        else if(state==1){ // 삿음
            int x = solve(idx + 1, 1, price);
            int y = solve(idx + 2, 0, price) + price[idx];
            ret = max(x,y);
             if(x>y) {
                cout<<idx<<"산 상태그대로갑니다\n";
            } else {
                cout<<idx<<"팝니다\n";
            }
        }
        
        cout<<idx<<' '<<ret<<'\n';
        return ret;
       
    }
    int maxProfit(vector<int>& prices) {
        memset(d, -1, sizeof(d));
        return solve(0, 0, prices);
    }
};