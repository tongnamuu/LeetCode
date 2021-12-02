class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0]*numCourses
        adj = collections.defaultdict(list)
        for p in prerequisites:
            adj[p[0]].append(p[1])
            indegree[p[1]] += 1
        q = deque()
        for v in range(numCourses):
            if indegree[v] == 0:
                q.append(v)
        ans = 0
        while q:
            now = q.popleft()
            ans += 1
            for nxt in adj[now]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    q.append(nxt)
        return ans == numCourses