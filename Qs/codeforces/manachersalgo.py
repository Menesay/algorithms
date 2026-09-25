import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        a = [int(x) for x in data[idx:idx+2*n]]
        idx += 2*n
        N = 2*n
        pos1 = [-1]*n
        pos2 = [-1]*n
        for i in range(N):
            v = a[i]
            if pos1[v] == -1: pos1[v] = i
            else: pos2[v] = i
        
        d1 = [0]*N
        l, r = 0, -1
        for i in range(N):
            k = 1 if i > r else min(d1[l+r-i], r-i+1)
            while i-k >= 0 and i+k < N and a[i-k] == a[i+k]:
                k += 1
            d1[i] = k
            if i+k-1 > r:
                l = i-k+1; r = i+k-1
        
        d2 = [0]*N
        l, r = 0, -1
        for i in range(N):
            k = 0 if i > r else min(d2[l+r-i+1], r-i+1)
            while i-k-1 >= 0 and i+k < N and a[i-k-1] == a[i+k]:
                k += 1
            d2[i] = k
            if i+k-1 > r:
                l = i-k; r = i+k-1
        
        SZ = 2*N - 1
        l_star = [-1] * SZ
        for i in range(N):
            l_star[2*i] = i - d1[i] + 1
        for i in range(1, N):
            if d2[i] > 0:
                l_star[2*i - 1] = i - d2[i]
        
        val_sets = [[] for _ in range(SZ)]
        for v in range(n):
            S = pos1[v] + pos2[v]
            ls = l_star[S]
            if ls != -1 and pos1[v] >= ls:
                val_sets[S].append(v)
        for i in range(N):
            val_sets[2*i].append(a[i])
        
        ans = 0
        for S in range(SZ):
            if l_star[S] == -1: continue
            vs = sorted(set(val_sets[S]))
            mex = 0
            for v in vs:
                if v == mex: mex += 1
                elif v > mex: break
            if mex > ans: ans = mex
        
        out.append(str(ans))
    
    sys.stdout.write('\n'.join(out) + '\n')

main()