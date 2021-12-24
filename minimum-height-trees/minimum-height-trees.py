class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        adj = collections.defaultdict(list)
        degree = [0]*n
        for e in edges:
            adj[e[0]].append(e[1])
            adj[e[1]].append(e[0])
            degree[e[0]] += 1
            degree[e[1]] += 1
        q = deque()
        for i in range(n):
            if degree[i] == 1:
                q.append(i)
        total = n
        while total > 2:
            k = len(q)
            total -= k
            while k > 0:
                k -= 1
                now = q.popleft()
                for next in adj[now]:
                    degree[next] -= 1
                    if degree[next] == 1:
                        q.append(next)
        return list(q)
                
        