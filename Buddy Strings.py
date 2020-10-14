class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        n = len(A)
        if n != len(B):
            return False
        idx1, idx2, cnt = -1,-1, 0
        for i in range(n):
            if A[i] == B[i]:
                continue
            cnt+=1
            if idx1 == -1:
                idx1 = i
            elif idx2 == -1:
                idx2 = i
            else:
                return False
        if cnt == 0:
            d = collections.defaultdict(int)
            for ch in A:
                d[ch] += 1
                if d[ch] >= 2:
                    return True
            return False
        elif cnt==2:
            return A[idx1] == B[idx2] and A[idx2] == B[idx1]
        else:
            return False
