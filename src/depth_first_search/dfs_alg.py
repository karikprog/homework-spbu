class Graph:
    def __init__(self):
        self._index = 0
        self._traversal = None
        self.graph = {}

    def __iter__(self):
        if not self.graph:
            self._traversal = []
        else:
            start = next(iter(self.graph))
            self._traversal = self.dfs(start)

        self._index = 0
        return self

    def add_node(self, node):
        if node not in self.graph:
            self.graph[node] = set()

    def add_edge(self, node1, node2):
        self.add_node(node1)
        self.add_node(node2)

        self.graph[node1].add(node2)
        self.graph[node2].add(node1)

    def dfs(self, start_node):
        if start_node not in self.graph:
            return []

        visited = set()
        stack = [start_node]
        traversal_order = []

        while stack:
            current_node = stack.pop()

            if current_node not in visited:
                traversal_order.append(current_node)
                visited.add(current_node)

                neighbors = sorted(self.graph[current_node], reverse=True)
                for val in neighbors:
                    if val not in visited:
                        stack.append(val)
        return traversal_order

    def __next__(self):
        if self._index < len(self._traversal):
            r = self._traversal[self._index]
            self._index += 1
            return r
        raise StopIteration


g = Graph()
g.add_edge(1, 2)
g.add_edge(2, 7)
g.add_edge(7, 9)
g.add_edge(7, 8)
g.add_edge(1, 3)
g.add_edge(3, 4)
g.add_edge(3, 5)

for it in g:
    print(it)

print(g.dfs(1))
