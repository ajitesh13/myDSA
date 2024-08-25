nodes = 5
parent = [i for i in range(nodes)] # parent array 
size = [1] * nodes # size array

def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

# union by size
def union(x, y):
    rootX = find(x)
    rootY = find(y)
    if rootX != rootY:
        if size[rootX] < size[rootY]:
            parent[rootX] = rootY
            size[rootY] += size[rootX]
        else:
            parent[rootY] = rootX
            size[rootX] += size[rootY]

# give some example usings the above functions
union(0, 1)
union(1, 2)
union(3, 4)
print(parent)
print(size)

# Output:
# [0, 0, 0, 3, 3]
# [3, 1, 1, 2, 1]

