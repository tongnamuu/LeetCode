class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> indegree(n);
        vector<vector<int>>adj(n);
        for(auto& e:invocations) {
            int from = e[0];
            int to = e[1];
            adj[from].push_back(to);
            indegree[to]++;
        }
        vector<int>ans;
        queue<int>q;
        vector<int>d(n, 0);


        d[k] = 1;
        q.push(k);

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(int next:adj[now]) {
                indegree[next]--;
                if(d[next]==0) {
                    q.push(next);
                    d[next] = 1;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(d[i]==0) ans.push_back(i);
            else if(d[i]==1 && indegree[i]>0) {
                vector<int>temp(n);
                for(int j=0;j<n;j++) {
                    temp[j] = j;
                }
                return temp;
            }
        }
        return ans;
    }
};