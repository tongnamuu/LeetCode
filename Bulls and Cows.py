class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        a, b = 0, 0
        s_dict = collections.defaultdict(int)
        g_dict = collections.defaultdict(int)
        
        for s, g in zip(secret, guess):
            if s == g:
                a += 1
            else:
                s_dict[s] += 1
                g_dict[g] += 1
        for c in g_dict:
            b += min(g_dict[c], s_dict[c])
        return f'{a}A{b}B'
