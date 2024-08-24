

def earliestAcq(logs, n: int) -> int:
    parent = [i for i in range(n)]

    def find(x):  # finds the id/leader of a node
        if parent[x] == x:
            return x
        parent[x] = find(parent[x])
        return parent[x]

    def Union(x, y):  # merges two disjoint sets into one set
        x = find(x)
        y = find(y)
        parent[x] = y

    logs.sort(key=lambda x: x[0])  # sorts friendships by timestamp
    components = n
    for friendship in logs:
        timestamp = friendship[0]
        x = friendship[1]
        y = friendship[2]
        if find(x) != find(y):  # merge two disjoint sets
            Union(x, y)
            components -= 1
        if components == 1:  # reached connected graph
            return timestamp
    return -1


logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]]
n = 4


logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]]
n = 6
print(earliestAcq(logs, n))