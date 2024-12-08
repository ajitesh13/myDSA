edges = [[1,2,2],[1,3,1],[2,4,1],[3,7,1],[4,5,5],[4,6,2],[7,6,3],[5,9,3],[6,8,7],[7,10,8],[9,11,2],[8,11,3],[10,11,2]]
n = 11

dist = [float('inf') for _ in range(n + 1)] 

dist[1] = 0
for _ in range(n - 1):
    for u, v, wt in edges:
        if dist[u] != float('inf') and dist[u] + wt < dist[v]:
            dist[v] = dist[u] + wt

for u, v, wt in edges:
    if dist[u] != float('inf') and dist[u] + wt < dist[v]:
        print("Graph contains negative edge")
        break

print(dist[1:])