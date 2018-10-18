import sys, time
G=[[0, 4, 0, 0, 0, 0, 0, 8, 0],
   [4, 0, 8, 0, 0, 0, 0, 11, 0],
   [0, 8, 0, 7, 0, 4, 0, 0, 2],
   [0, 0, 7, 0, 9, 14, 0, 0, 0],
   [0, 0, 0, 9, 0, 10, 0, 0, 0],
   [0, 0, 4, 14, 10, 0, 2, 0, 0],
   [0, 0, 0, 0, 0, 2, 0, 1, 6],
   [8, 11, 0, 0, 0, 0, 1, 0, 7],
   [0, 0, 2, 0, 0, 0, 6, 7, 0]]

V=len(G[0])

def min_dist( dist, spt): #spt= shortest path tree
    min = sys.maxint
    for v in range(V):
        if dist[v] < min and spt[v] == False:
            min = dist[v]
            min_index = v

    return min_index

def dijkstra(G,src):
    global V
    dist = [sys.maxint] * V
    dist[src] = 0
    spt = [False] * V
    for cout in range(V):
        u = min_dist(dist, spt)
        spt[u] = True
        for v in range(V):
            if G[u][v] > 0 and spt[v] == False and dist[v] > dist[u] + G[u][v]:
                    dist[v] = dist[u] + G[u][v]

    print "Vertex \t Distance from Source"
    for node in range(V):
        print node,"\t",dist[node]
        
a=time.clock()
dijkstra(G,0)
print "Time taken is "+str(time.clock()-a)

