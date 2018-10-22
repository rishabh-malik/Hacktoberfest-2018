from collections import defaultdict 
class Graph: 
	def __init__(self): 
		self.graph = defaultdict(list) 

	def addEdge(self,u,v): 
		self.graph[u].append(v) 

	def DFSUtil(self,v,visited): 
		visited[v]= True
		print(v, )

		for i in self.graph[v]: 
			if visited[i] == False: 
				self.DFSUtil(i, visited) 

	def DFS(self,v): 
		visited = [False]*(len(self.graph)) 

		self.DFSUtil(v,visited) 

g = Graph() 
g.addEdge(4, 6) 
g.addEdge(5, 3) 
g.addEdge(2, 3) 
g.addEdge(7, 9) 
g.addEdge(1, 3) 
g.addEdge(3, 0) 

print("DFS starting from 2:")
g.DFS(2)
