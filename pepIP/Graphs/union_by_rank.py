nodes = 5
parent = [i for i in range(nodes)] # parent array
rank = [0] * nodes # rank array

def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

# union by rank
def union(x, y):
    rootX = find(x)
    rootY = find(y)
    if rootX != rootY:
        if rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
        elif rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        else:
            parent[rootY] = rootX
            rank[rootX] += 1 # increase the rank if they are the same 

# give some example usings the above functions
union(0, 1)
union(1, 2)
union(3, 4)
print(parent)
print(rank)

# Output:
# [0, 0, 0, 3, 3]
# [1, 0, 0, 1, 0]


