class Solution:
    def manhattan_distance(self, point1, point2):
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:

        n = len(points)
        adj = defaultdict(set)
        for i in range(n):
            for j in range(n):
                if i != j:
                    xi, yi = points[i][0], points[i][1]
                    xj, yj = points[j][0], points[j][1]
                    point1, point2 = (xi, yi), (xj, yj)
                    manhat_dist = self.manhattan_distance(point1, point2)
                    adj[point1].add((point2, manhat_dist))
                    adj[point2].add((point1, manhat_dist))
        
        minHeap = [(0, (points[0][0], points[0][1]))]
        visited = set((points[0][0], points[0][1]))
        total_wt = 0
        while len(visited) < n:
            curr_wt, curr_node  = heapq.heappop(minHeap)
            total_wt += curr_wt 
            
            for node, wt in adj[curr_node]:
                if node not in visited:
                    visited.add(node)
                    heapq.heappush(minHeap, (wt, node))
        
        return total_wt

                    


        