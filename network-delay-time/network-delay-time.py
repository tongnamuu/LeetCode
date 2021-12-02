class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        q = []
        dist = [1000000000] * (n + 1)
        adj = collections.defaultdict(list)
        for t in times:
            adj[t[0]].append((t[1], t[2]))
        dist[k] = 0
        heapq.heappush(q, (0, k))
        while q:
            cost, now = heapq.heappop(q)
            if dist[now] < cost:
                continue
            for next, c in adj[now]:
                if dist[next] > cost + c:
                    dist[next] = cost + c
                    heapq.heappush(q, (cost+c, next))
        ans = dist[1]
        for i in range(2, n + 1):
            ans = dist[i] if dist[i] > ans else ans
        if ans == 1000000000:
            return -1
        return ans
