from collections import deque

def topological_sort(node, visited, adj_list, deq):
    if visited[node] == False:
        visited[node] = True
        for neighbour in adj_list[node]:
            if visited[neighbour] == False:
                topological_sort(neighbour, visited, adj_list, deq)
        deq.appendleft(node)

def main():
    list_of_edges = [[0, 1], [1, 3], [0, 2], [2, 3]]
    nodes = 4

    adj_list = [[] for _ in range(nodes)]
    for edge in list_of_edges:
        adj_list[edge[0]].append(edge[1])
    
    visited = [False] * nodes
    deq = deque([])

    for i in range(nodes):
        if visited[i] == False:
            topological_sort(i, visited, adj_list, deq)
    
    # 0, 2, 1, 3
    print(list(deq))

if __name__ == "__main__":
    main()