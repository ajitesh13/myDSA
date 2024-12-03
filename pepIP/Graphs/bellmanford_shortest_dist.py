def bellman_ford(graph, source):
    # Step 1: Initialize distances from source to all vertices as infinite
    distance = {vertex: float('inf') for vertex in graph}
    distance[source] = 0  # Distance to the source is 0

    # Step 2: Relax all edges |V| - 1 times
    for _ in range(len(graph) - 1):
        for u in graph:
            for v, weight in graph[u]:
                if distance[u] != float('inf') and distance[u] + weight < distance[v]:
                    distance[v] = distance[u] + weight

    # Step 3: Check for negative weight cycles
    for u in graph:
        for v, weight in graph[u]:
            if distance[u] != float('inf') and distance[u] + weight < distance[v]:
                print("Graph contains negative weight cycle")
                return None  # or raise an exception

    return distance

# Example usage:
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('C', -3), ('D', 2)],
    'C': [('D', 3)],
    'D': []
}

source_vertex = 'A'
distances = bellman_ford(graph, source_vertex)

if distances:
    print("Vertex Distance from Source:")
    for vertex, dist in distances.items():
        print(f"{vertex}: {dist}")
