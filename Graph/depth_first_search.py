def make_link(G, node1, node2, edge_value):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = edge_value
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = edge_value
    return G

def dfs(G, start):
    marked = {}
    for node in G:
        marked[node] = False
    pipe = [start]
    marked[start] = True
    while pipe:
        nextNode = pipe.pop()
        for neighbor in G[nextNode]:
            if marked[neighbor]:
                continue
            else:
                pipe.append(neighbor)
                print(neighbor)
                marked[neighbor] = True
    

if __name__ == "__main__":
    test_edges = [(0, 1), (0, 2), (1, 3), (1, 4), (2, 5), (2, 6)]
    G = {}
    for n1, n2 in test_edges:
        make_link(G, n1, n2, 1)
    
    dfs(G, 0)


