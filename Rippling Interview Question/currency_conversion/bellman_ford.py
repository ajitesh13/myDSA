from collections import defaultdict, deque

def bellman_ford_max_rate(conversions, source, target):
    # Build the graph as a list of edges
    edges = []
    for src, dest, rate in conversions:
        rate = float(rate)
        edges.append((src, dest, rate))
        edges.append((dest, src, 1 / rate))  # Reverse conversion

    # Initialize distances
    rates = defaultdict(lambda: 0)
    rates[source] = 1

    # Relax edges |V|-1 times
    for _ in range(len(rates) - 1):
        for src, dest, rate in edges:
            if rates[src] * rate > rates[dest]:
                rates[dest] = rates[src] * rate

    # Check for cycles (optional if needed)
    for src, dest, rate in edges:
        if rates[src] * rate > rates[dest]:
            raise ValueError("Graph contains a cycle with increasing rates")

    return rates.get(target, -1)

# Test Cases
conversions = [
    ("USD", "EUR", "0.95"),
    ("EUR", "JPY", "137"),
    ("USD", "JPY", "130"),
    ("JPY", "BTC", "0.001"),
    ("BTC", "INR", "30000"),
]

print(bellman_ford_max_rate(conversions, "USD", "JPY"))  # Should return 137
print(bellman_ford_max_rate(conversions, "USD", "BTC"))  # Should return 0.137
print(bellman_ford_max_rate(conversions, "USD", "INR"))  # Should return 4110.0
