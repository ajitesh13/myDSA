from collections import deque, defaultdict

def currencyConversion(currencies, source_currency, target_currency):
    adj = defaultdict(set)
    for currency1, currency2, conversion_rate in currencies:
        adj[currency1].add((currency2, conversion_rate))
    
    res = -float('inf')
    deq = deque([(source_currency, 1)])
    visited = set(source_currency)
    while deq:
        curr_currency, curr_rate = deq.popleft()
        if curr_currency == target_currency:
            return curr_rate
        for node, node_rate in adj[curr_currency]:
            if node not in visited:
                visited.add(node)
                deq.append((node, curr_rate * node_rate))

    return -1

currencies = [['a', 'b', 1.3], ['a', 'c', 1.5], ['c', 'b', 1.6]]
result = currencyConversion(currencies, 'b', 'c')
print(result)