def min_operations_to_non_decreasing(nums: List[int]) -> int:
    n = len(nums)
    if n <= 1:
        return 0

    prev = [i - 1 for i in range(n)]
    nxt = [i + 1 for i in range(n)]
    nxt[-1] = -1

    alive = [True] * n
    left_pos = list(range(n))  
    ver = [0] * n 

    bad = 0
    for i in range(n - 1):
        if nums[i] > nums[i + 1]:
            bad += 1
    if bad == 0:
        return 0

    heap = []
    for i in range(n - 1):
        heapq.heappush(
            heap,
            (nums[i] + nums[i + 1], left_pos[i], i, i + 1, ver[i], ver[i + 1]),
        )

    ops = 0

    while bad > 0:

        while True:
            s, lp, u, v, vu, vv = heapq.heappop(heap)
            if alive[u] and alive[v] and nxt[u] == v and ver[u] == vu and ver[v] == vv:
                break

        ops += 1

        p = prev[u]
        w = nxt[v]
        if p != -1 and nums[p] > nums[u]:
            bad -= 1
        if nums[u] > nums[v]:
            bad -= 1
        if w != -1 and nums[v] > nums[w]:
            bad -= 1

        nums[u] += nums[v]
        ver[u] += 1
        alive[v] = False

        nxt[u] = w
        if w != -1:
            prev[w] = u

        if p != -1 and nums[p] > nums[u]:
            bad += 1
        if w != -1 and nums[u] > nums[w]:
            bad += 1

        if p != -1:
            heapq.heappush(heap, (nums[p] + nums[u], left_pos[p], p, u, ver[p], ver[u]))
        if w != -1:
            heapq.heappush(heap, (nums[u] + nums[w], left_pos[u], u, w, ver[u], ver[w]))

    return ops

class Solution:
    def minimumPairRemoval(self, nums:List[int]) -> int:
        return min_operations_to_non_decreasing(nums)