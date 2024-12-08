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
    adj[u].add((v, wt))
    adj[v].add((u, 1 / wt))

def bfs(adj, source, destination):

    if source not in adj or destination not in adj:
        print("CurrencyError: Trying to convert to an invalid currency")
        return

    deq = deque([(source, 1)])
    while deq:
        curr_node, curr_rate = deq.popleft()
        if curr_node == destination:
            return curr_rate
        
        for neighbor, rate in adj[curr_node]:
            deq.append((neighbor, rate * curr_rate))
    
    return -1


print(dfs_best_rate_wrapper(graph, "USD", "JPY"))  
print(dfs_best_rate_wrapper(graph, "BTC", "INR"))  
print(dfs_best_rate_wrapper(graph, "USD", "INR")) 
print(dfs_best_rate_wrapper(graph, "CNY", "USD")) 
        


