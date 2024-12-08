edges = [[1,2,1],[1,4,1],[1,5,3],[2,3,1],[4,3,2],[3,5,1]]

n = 5
dist = [[float('inf') for i in range(n + 1)] for j in range(n + 1)]

for u, v, wt in edges:
    dist[u][v] = wt

for k in range(n):
    for i in range(n + 1):
        for j in range(n + 1):
            if i == j:
                dist[i][j] = 0
            
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(n + 1):
    for j in range(n + 1):
        if dist[i][j] != float('inf'):
            print(f"{i},{j}:{dist[i][j]}")