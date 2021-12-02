class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        dist = [[1000000000]*102 for _ in range(102)]
        adj = collections.defaultdict(list)
        for f in flights:
            adj[f[0]].append((f[1], f[2]))
        q = []
        heapq.heappush(q, (0, src, 0))
        dist[src][0] = 0
        while q:
            cost, now, cnt = heapq.heappop(q)
            if cnt > k:
                continue
            for next, c in adj[now]:
                if dist[next][cnt + 1] > c + cost:
                    dist[next][cnt + 1] = c + cost
                    heapq.heappush(q, (c + cost, next, cnt + 1))
        ans = dist[dst][0]
        for i in range(1, k + 2):
            ans = ans if dist[dst][i] > ans else dist[dst][i]
        if ans == 1000000000:
            return -1
        return ans
            