
from json.encoder import INFINITY
import sys
import heapq
import itertools
from collections import defaultdict, Counter, deque

sys.setrecursionlimit(int(1e6))

infile = sys.argv[1] if len(sys.argv)>1 else 'input.in'

G = []
for line in open(infile):
    G.append([int(x) for x in line.strip()])

def neighbours4(r, c, h ,w):
    for dr, dc in ((1,0), (-1, 0), (0, 1), (0, -1)):
        rr, cc = (r + dr, c + dc)
        if 0 <= rr < w and 0 <= cc < h:
            yield rr, cc

def dijkstra():
    h, w = len(G), len(G[0])
    source = (0,0)
    dest = (h - 1, w - 1)
    
    # We start with the source in our queue of nodes to visit
    queue = [(0, source)]
    minDist = defaultdict(lambda: INFINITY, {source: 0})
    visited = set()

    while queue:
        # Get the node with the lowest distance in the queue
        dist, node = heapq.heappop(queue)

        # If we're at our dest we win
        if node == dest:
            return dist
        
        # If we have visited this node, skip it
        if node in visited:
            continue

        # Now we have visited this node
        visited.add(node)

        # Row and col of our node
        r, c = node

        # We go through all of our neighbours
        for n in neighbours4(r, c, w, h):
            if n in visited:
                continue
            
            # Calculate the total distance from the source to this neighbour (n)
            # passning through this node
            nr, nc = n
            newDist = dist + G[nr][nc]

            # If the distance is lower than the minimum distance we have to reach this neighbour
            # Then update its minimum distance and add it to the queue
            if newDist < minDist[n]:
                minDist[n] = newDist
                heapq.heappush(queue, (newDist, n))
                
    return INFINITY


print(dijkstra())