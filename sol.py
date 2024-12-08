from collections import defaultdict
import heapq

edges = [[1,2,2],[1,3,1],[2,4,1],[3,7,1],[4,5,5],[4,6,2],[7,6,3],[5,9,3],[6,8,7],[7,10,8],[9,11,2],[8,11,3],[10,11,2]]
adj = defaultdict(list)
for u, v, wt in edges:
    adj[u].append((v, wt))

n = 11

dist = [float('inf') for _ in range(n + 1)] 
source = 1
dist[source] = 0
minHeap = [(0, source)]

while minHeap:
    curr_dist, u = heapq.heappop(minHeap)

    if curr_dist <= dist[u]:
        for v, wt in adj[u]:
            if dist[u] + wt < dist[v]:
                dist[v] = dist[u] + wt
                heapq.heappush(minHeap, (dist[v], v)) 

print(dist)