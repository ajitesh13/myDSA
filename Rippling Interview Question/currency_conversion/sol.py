from collections import defaultdict, deque

n = 5
conversions = [
    ("USD", "EUR", "0.95"),
    ("EUR", "JPY", "137"),
    ("USD", "JPY", "130"),
    ("JPY", "BTC", "0.001"),
    ("BTC", "INR", "30000"),
]
edges = []
for u, v, wt in conversions:
    edges.append((u, v, float(wt)))
    edges.append((v, u, 1 / float(wt)))

def convert_bellmanford(edges, source, destination):
    result_hmap = {source: 1}

    for _ in range(n):
        for u, v, wt in edges:
            if u in result_hmap:
                result_hmap[v] = min(result_hmap.get(v, float('inf')), result_hmap[u] * wt)

    return result_hmap.get(destination, -1)


print(convert_bellmanford(edges, "USD", "JPY"))  
print(convert_bellmanford(edges, "BTC", "INR"))  
print(convert_bellmanford(edges, "USD", "INR")) 
print(convert_bellmanford(edges, "CNY", "USD")) 
        


