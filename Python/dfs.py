from collections import defaultdict 
class Graph: 
	def __init__(self): 

		self.graph = defaultdict(list) 

	def addEdge(self, u, v): 
		self.graph[u].append(v) 

	def DFSUtil(self, v, visited): 

		visited[v] = True
		print(v, end = ' ') 

		for i in self.graph[v]: 
			if visited[i] == False: 
				self.DFSUtil(i, visited) 

	def DFS(self, v): 
		visited = [False] * (len(self.graph)) 

		self.DFSUtil(v, visited) 

g = Graph() 
# add the edges using addEdge method in above class.
print("dfs from the given vertex is") 
g.DFS(vertex) 

