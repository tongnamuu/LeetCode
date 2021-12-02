class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = collections.defaultdict(list)
        visit = collections.defaultdict(list)
        for t in tickets:
            adj[t[0]].append([t[1], False])
        for k in adj:
            adj[k].sort()
        ans = []
        def dfs(now):
            for idx, (next, used) in enumerate(adj[now]):
                if not used:
                    adj[now][idx][1] = True
                    dfs(next)
            ans.append(now)
        dfs("JFK")
        return ans[::-1]