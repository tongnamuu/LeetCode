class Solution {
public:
    int d[500001];
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0) return true;
        int n = arr.size();
        queue<int>q;
        q.push(start);
        d[start] = 1;
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            int idx = now + arr[now];
            if(idx>=0&&idx<n && d[idx]==0) {
                q.push(idx);
                d[idx] = 1;
            }
            idx = now - arr[now];
            if(idx>=0&&idx<n && d[idx]==0) {
                q.push(idx);
                d[idx] = 1;
            }
        }
        for(int i=0;i<n;i++) {
            if(arr[i]==0 && d[i]==1) return true;
        }
        return false;
    }
};