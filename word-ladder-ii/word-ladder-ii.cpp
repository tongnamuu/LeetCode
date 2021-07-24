class Solution {
public:
    bool cmp(const string& s, const string& p) {
        int cnt = 0;
        int n = s.length();
        for(int i=0;i<n;++i){
            if(s[i]!=p[i]) ++cnt;
        }
        return cnt==1;
    }
    int a[1001][1001];
    vector<int>adj[1005];
    int visit[1005];
    int dist[1001];
    vector<vector<string>>ans;
    int minlen = 2000;
    void dfs(int end, int idx, vector<string>& cur, const vector<string>& words) {
        if(cur.size() > minlen) return;
        if(idx==end) {
            if(cur.size() < minlen) {
                ans.clear();
                minlen = cur.size();
                vector<string>temp = cur;
                ans.push_back(temp);
            } else if(cur.size()==minlen) {
                vector<string>temp = cur;
                ans.push_back(temp);
            }
            return;
        }
        for(int i : adj[idx]){
            if(visit[i]) continue;
            visit[i] = 1;
            cur.push_back(words[i]);
            dfs(end, i, cur, words);
            cur.pop_back();
            visit[i] = 0;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int endable = -1;
        for(int i=0;i<n;++i){
            if(wordList[i] == endWord) {
                endable = i;
                break;
            }
        }
        if(endable == -1) return ans;
        queue<int>q;
        vector<int>start;
        map<string, int> m;
        for(int i=0;i<n;++i){
            m[wordList[i]] = i;
            if(cmp(beginWord, wordList[i])) {
                q.push(i);
                start.push_back(i);
                dist[i] = 1;
            }
        }
        while(!q.empty()) {
            int idx = q.front();q.pop();
            for(int i=0;i<wordList[idx].length();++i) {
                char temp = wordList[idx][i];
                for(char c = 'a'; c<='z';++c){
                    if(c==temp) continue;
                    wordList[idx][i] = c;
                    auto it = m.find(wordList[idx]);
                    if(it == m.end()) continue;
                    int find = it->second;
                    if(find < n && wordList[find] == wordList[idx]) {
                        if(dist[find]==0){
                            adj[idx].push_back(find);
                            q.push(find);
                            dist[find] = dist[idx] + 1;
                        }   else if(dist[find] == dist[idx] + 1) {
                            adj[idx].push_back(find);
                        }
                    }
                }
                wordList[idx][i] = temp;
            }
        }
        vector<string>temp(2);
        temp[0] = beginWord;
        for(int i : start) {
            temp[1] = wordList[i];
            dfs(endable, i, temp, wordList);
        }
        return ans;
    }
};