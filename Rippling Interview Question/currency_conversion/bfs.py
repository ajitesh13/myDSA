from collections import defaultdict, deque

edges  = [
    ("USD", "EUR", "0.95"),
    ("EUR", "JPY", "137"),
    ("USD", "JPY", "130"),
    ("JPY", "BTC", "0.001"),
    ("BTC", "INR", "30000"),
]

adj = defaultdict(set)
for u, v, wt in edges:
    adj[u].add((v, float(wt)))
    adj[v].add((u, 1 / float(wt)))

def bfs(adj, source, destination):

    if source not in adj or destination not in adj:
        return -1

    deq = deque([(source, 1.00)])
    while deq:
        curr_node, curr_rate = deq.popleft()
        if curr_node == destination:
            return curr_rate
        
        for neighbor, rate in adj[curr_node]:
            deq.append((neighbor, rate * curr_rate))
    
    return -1


print(bfs(adj, "USD", "JPY"))  
print(bfs(adj, "BTC", "INR"))  
print(bfs(adj, "USD", "INR")) 
print(bfs(adj, "CNY", "USD")) 
        


