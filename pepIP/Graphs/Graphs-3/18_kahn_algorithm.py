from collections import defaultdict, deque

vertices = 6
edges = [(5,2),(5,0),(4,0),(4,1),(2,3),(3,1)]

adj = defaultdict(set)
indegree = {i:0 for i in range(vertices)}
for u, v in edges:
    adj[u].add(v)
    indegree[v] += 1

deq = deque([])
for node, indeg in indegree.items():
    if indeg == 0:
        deq.append(node)

topological_order = []
while deq:
    current_node = deq.popleft()
    topological_order.append(current_node)

    for node in adj[current_node]:
        indegree[node] -= 1
        if indegree[node] == 0:
            deq.append(node)

if len(topological_order) != vertices:
    print("Error: Cycle detected")
    return 

print(topological_order)

