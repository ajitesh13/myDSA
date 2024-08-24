def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start)  # Or append to a result list
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Example graph
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B'],
    'F': ['C']
}

dfs(graph, 'A')

graph2 = {
    1: [2,3],
    2: [1, 4,5],
    3: [1, 6],
    4: [2],
    5: [2],
    6: [3]
}

dfs(graph2, 1)

'''
    A
   / \
  B   C
 / \   \
D   E   F

    1
   / \
  2   3
 / \   \
4   5   6


'''