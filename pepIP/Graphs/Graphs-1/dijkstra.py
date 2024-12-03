import heapq

def dijkstra(graph, source):
    # Step 1: Initialize distances and priority queue
    distance = {vertex: float('inf') for vertex in graph}
    distance[source] = 0
    priority_queue = [(0, source)]  # (distance, vertex)

    while priority_queue:
        # Step 2: Get the vertex with the smallest distance
        current_distance, current_vertex = heapq.heappop(priority_queue)

        # Step 3: If the distance is greater than the recorded distance, skip it
        if current_distance > distance[current_vertex]:
            continue

        # Step 4: Relax all adjacent edges
        for neighbor, weight in graph[current_vertex]:
            distance_through_vertex = current_distance + weight

            # If a shorter path to the neighbor is found
            if distance_through_vertex < distance[neighbor]:
                distance[neighbor] = distance_through_vertex
                heapq.heappush(priority_queue, (distance_through_vertex, neighbor))

    return distance

# Example usage:
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('C', 2), ('D', 5)],
    'C': [('D', 1)],
    'D': []
}

source_vertex = 'A'
distances = dijkstra(graph, source_vertex)

print("Vertex Distance from Source:")
for vertex, dist in distances.items():
    print(f"{vertex}: {dist}")
