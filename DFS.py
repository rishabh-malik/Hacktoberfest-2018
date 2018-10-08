from collections import defaultdict


class Graph:

    def __init__(self):
        self.graph = defaultdict(list)  

    def addEdge(self, i, j):
        self.graph[i].append(j) 
 
    def DFSUtil(self, j, isvisited):
        isvisited[j] = True
        print(j)
        for i in self.graph[j]:
            if isvisited[i] == False:
                self.DFSUtil(i, isvisited)

    def DFS(self, j):
        visited = [False] * (len(self.graph))
        self.DFSUtil(j, visited)


g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

for i in range(4):

   
    print("DFS " + str(i) + ": ")

    g.DFS(i)
