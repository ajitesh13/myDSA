from collections import defaultdict

def dfs_best_rate(graph, current, target, visited, current_rate, best_rates):
    if current == target:
        return current_rate

    visited.add(current)
    max_rate = -1

    for neighbor, rate in graph[current]:
        new_rate = current_rate * rate
        if new_rate > best_rates.get(neighbor, 0):
            best_rates[neighbor] = new_rate
            if neighbor not in visited:
                result = dfs_best_rate(graph, neighbor, target, visited, new_rate, best_rates)
                max_rate = max(max_rate, result)

    visited.remove(current)
    return max_rate

def dfs_best_rate_wrapper(graph, source, target):
    if source not in graph or target not in graph:
        return -1
    best_rates = {source: 1}
    return dfs_best_rate(graph, source, target, set(), 1, best_rates)

def build_graph(conversions):
    graph = defaultdict(list)
    for src, dest, rate in conversions:
        rate = float(rate)
        graph[src].append((dest, rate))
        graph[dest].append((src, 1 / rate))  # Reverse conversion
    return graph

# Test Cases
conversions = [
    ("USD", "EUR", "0.95"),
    ("EUR", "JPY", "137"),
    ("USD", "JPY", "130"),
    ("JPY", "BTC", "0.001"),
    ("BTC", "INR", "30000"),
]
graph = build_graph(conversions)
print(dfs_best_rate_wrapper(graph, "USD", "JPY"))  
print(dfs_best_rate_wrapper(graph, "BTC", "INR"))  
print(dfs_best_rate_wrapper(graph, "USD", "INR")) 
print(dfs_best_rate_wrapper(graph, "CNY", "USD")) 
